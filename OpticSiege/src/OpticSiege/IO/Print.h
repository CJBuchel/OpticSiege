#pragma once

#include <iostream>

namespace OPS {

	/**
	 * Generic print
	 */
	template <typename T>
	static void printnl(T value) {
		std::cout << "[OPS IO]: " << value;
	}

	/**
	 * Generic print line
	 */
	template <typename T>
	static void print(T value) {
		std::cout << "[OPS IO]: " << value << std::endl;
	}
}