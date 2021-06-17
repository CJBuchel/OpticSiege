// #pragma once

// #include <iostream>
// #include <glad/glad.h>
// #include <GLFW/glfw3.h>

// #include <fstream>
// #include <string>
// #include <sstream>

// /**
//  * Local files
//  */
// /**
// * Error handle wrapper for GL
// */
// #ifdef _MSC_VER
// #define ASSERT(x) if (!(x)) __debugbreak();
// #else
// #define ASSERT(x) // DOES NOTHING
// #endif
// #define GLCall(x) glClearError(); x; ASSERT(glLogCall(#x, __FILE__, __LINE__))

// /**
// * File path for res (compat)
// */
// #ifdef _MSC_VER // if vs

// #ifdef OPS_DEBUG // if debug
// #define RES_PATH "res/"
// #endif

// #ifdef OPS_RELEASE // if release
// #define RES_PATH "../../../../Test/res/"
// #endif

// #else // linux
// #define RES_PATH "Test/res/" // ONLY WORKD IF USING RUN.SH
// #endif


// namespace OPS_Test {

// 	/**
// 	 * Global printer
// 	 */
// 	template <typename T>
// 	static void print(T var) {
// 		std::cout << var;
// 	}

// 	template <typename T>
// 	static void println(T var) {
// 		std::cout << var << std::endl;
// 	}
// };