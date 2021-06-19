#include "ops_pch.h"
#include "OpticSiege/Core/ErrorHandles/GLHandles.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

bool glLogCall(const char *function, const char *file, int line) {
 while (GLenum error = glGetError()) {
	 std::cout << "[OpenGL Error] (" << error << "): " << function << " file: " << file << std::endl;
	 return false;
 }
 return true;
}