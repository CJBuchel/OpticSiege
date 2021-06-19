#pragma once

#include "OpticSiege/Core/ErrorHandles/Assert.h"

/**
* OpenGL handles
*/

//#define _USE_OPENGL // We only support opengl currently (done inside platformdetection.h)
#ifdef _USE_OPENGL

/**
* clear all the current errors
*/
#define GLClearError while(glGetError() != GL_NO_ERROR)


/**
* Log gl error "if error"
*/
static bool glLogCall(const char *function, const char *file, int line);

/**
* OpenGL caller
*/

#define GLCall(x) GLClearError; x; OPS_CORE_ASSERT(glLogCall(#x, __FILE__, __LINE__))
#endif