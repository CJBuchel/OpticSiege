#include <iostream>

namespace OPS_Test {

	/**
	 * Global printer
	 */
	template <typename T>
	static void print(T var) {
		std::cout << var;
	}

	template <typename T>
	static void println(T var) {
		std::cout << var << std::endl;
	}
};