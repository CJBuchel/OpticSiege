#include "main.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <fstream>
#include <string>
#include <sstream>

#ifdef _MSC_VER
#define ASSERT(x) if (!(x)) __debugbreak();
#else
#define ASSERT(x) std::cout << "NOT MSC CANNOT BREAK" << std::endl;
#endif
#define GLCall(x) glClearError(); x; ASSERT(glLogCall(#x, __FILE__, __LINE__))

static void glClearError() {
	while (glGetError() != GL_NO_ERROR);
}

static bool glLogCall(const char *function, const char *file, int line) {
	while (GLenum error = glGetError()) {
		std::cout << "[OpenGL Error] (" << error << "): " << function << " " << "file: " << file << std::endl;
		return false;
	}

	return true;
}

struct ShaderProgramSources {
	std::string vertexSource;
	std::string fragmentSource;
};

static ShaderProgramSources parseShader(const std::string &filepath) {
	std::ifstream stream(filepath);

	enum class ShaderType {
		NONE = -1,
		VERTEX = 0,
		FRAGMENT = 1
	}; ShaderType type = ShaderType::NONE;

	std::string line;
	std::stringstream ss[2];
	while (getline(stream, line)) {
		if (line.find("#shader") != std::string::npos) {
			if (line.find("vertex") != std::string::npos) {
				// Set mode to vertex
				type = ShaderType::VERTEX;
			} else if (line.find("fragment") != std::string::npos) {
				// set mode to fragment
				type = ShaderType::FRAGMENT;
			}
		} else {
			ss[(int)type] << line << '\n';
		}
	}

	return { ss[0].str(), ss[1].str() };
}

static unsigned int compileShader(unsigned int type, const std::string &source) {
	unsigned int id = glCreateShader(type);
	std::cout << "Shader type: " << type << std::endl;
	const char *src = source.c_str();
	GLCall(glShaderSource(id, 1, &src, nullptr));
	GLCall(glCompileShader(id));

	// Error handling
	int result;
	GLCall(glGetShaderiv(id, GL_COMPILE_STATUS, &result));
	if (result == GL_FALSE) {
		int length;
		GLCall(glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length));
		char *message = (char *)alloca(length * sizeof(char));

		GLCall(glGetShaderInfoLog(id, length, &length, message));
		std::cout << "Failed to compile " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << " shader!" << std::endl;
		OPS_Test::println(message);
		GLCall(glDeleteShader(id));
		return 0;
	}

	std::cout << "Shader ID: " << id << std::endl;

	return id;
}

static unsigned int createShader(const std::string &vertexShader, const std::string &fragmentShader) {
	unsigned int program = glCreateProgram();
	unsigned int vs = compileShader(GL_VERTEX_SHADER, vertexShader);
	unsigned int fs = compileShader(GL_FRAGMENT_SHADER, fragmentShader);

	GLCall(glAttachShader(program, vs));
	GLCall(glAttachShader(program, fs));
	GLCall(glLinkProgram(program));
	GLCall(glValidateProgram(program));

	GLCall(glDeleteShader(vs));
	GLCall(glDeleteShader(fs));

	return program;
}

void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
	GLCall(glViewport(0, 0, width, height));
}

int main() {
	OPS_Test::println("Hello world from OPS");

	/**
	* GLFW Initialize
	*/
	if (!glfwInit())
		return -1;
	//glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	//glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


	GLFWwindow *window = glfwCreateWindow(640, 480, "LearnOpenGL", NULL, NULL); // Main window
	if (!window) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	/**
	* GLAD initialize
	*/
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}


	/**
	* GL viewporet
	*/
	GLCall(glViewport(0, 0, 640, 480));
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);


	std::cout << glGetString(GL_VERSION) << std::endl;

	float positions[] = {
		-0.5f, -0.5f,
		0.5f, -0.5f,
		0.5f, 0.5f,
		-0.5f, 0.5f,
	};

	unsigned int indicies[] = {
		0, 1, 2,
		2, 3, 0
	};

	/**
	* Vertex buffer & attributes
	*/
	unsigned int buffer;
	GLCall(glGenBuffers(1, &buffer));
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, buffer));
	GLCall(glBufferData(GL_ARRAY_BUFFER, 6 * 2 * sizeof(float), positions, GL_STATIC_DRAW));

	GLCall(glEnableVertexAttribArray(0));
	GLCall(glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0));

	unsigned int ibo;
	GLCall(glGenBuffers(1, &ibo));
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo));
	GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(unsigned int), indicies, GL_STATIC_DRAW));

	/**
	 * Vertext shader
	 */

	ShaderProgramSources shaderSources = parseShader("res/shaders/Basic.shader");

	unsigned int shader = createShader(shaderSources.vertexSource, shaderSources.fragmentSource);
	GLCall(glUseProgram(shader));

	//glBindBuffer(GL_ARRAY_BUFFER, 0);

	/**
	* Super loop
	*/
	while (!glfwWindowShouldClose(window)) {
		GLCall(glClear(GL_COLOR_BUFFER_BIT));

		GLCall(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr));

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	GLCall(glDeleteProgram(shader));

	glfwTerminate();

	return 0;
}