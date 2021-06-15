#pragma once

/**
* Error handle wrapper for GL
*/
#ifdef _MSC_VER
#define ASSERT(x) if (!(x)) __debugbreak();
#else
#define ASSERT(x) // DOES NOTHING
#endif
#define GLCall(x) glClearError(); x; ASSERT(glLogCall(#x, __FILE__, __LINE__))

/**
* File path for res (compat)
*/
#ifdef _MSC_VER // if vs

#ifdef OPS_DEBUG // if debug
#define RES_PATH "res/"
#endif

#ifdef OPS_RELEASE // if release
#define RES_PATH "../../../../Test/res/"
#endif

#else // linux
#define RES_PATH "../../../../Test/res/"
#endif