// #pragma once

// #include "OpticSiege/ErrorHandles/Assert.h"
// #include "pch.h"

// /**
// * OpenGL handles
// */

// //#define _USE_OPENGL // We only support opengl currently
// #ifdef _USE_OPENGL
// #include "glad/glad.h"
// #include "GLFW/glfw3.h"


// /**
// * clear all the current errors
// */
// #define GLClearError while(glGetError() != GL_NO_ERROR)


// /**
// * Log gl error "if error"
// */
// static bool glLogCall(const char *function, const char *file, int line) {
// 	while (GLenum error = glGetError()) {
// 		std::cout << "[OpenGL Error] (" << error << "): " << function << " file: " << file << std::endl;
// 		return false;
// 	}
// 	return true;
// }

// /**
// * OpenGL caller
// */

// #define GLCall(x) GLClearError; x; ASSERT(glLogCall(#x, __FILE__, __LINE__))
// #endif