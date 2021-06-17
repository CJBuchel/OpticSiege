#pragma once

#include "OpticSiege/Logging/Log.h"

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

#ifdef OPS_DEBUG
	#define OPS_CORE_PRINT(...) ::OPS::print(__VA__ARGS__)
	#define OPS_CORE_PRINT_INFO(...) ::OPS::Log::getCoreLogger()->info(__VA_ARGS__)
	#define OPS_CORE_PRINT_ERROR(...) ::OPS::Log::getCoreLogger()->error(__VA_ARGS__)
	#define OPS_CORE_PRINT_WARN(...) ::OPS::Log::getCoreLogger()->warn(__VA_ARGS__)
	#define OPS_CORE_PRINT_TRACE(...) ::OPS::Log::getCoreLogger()->trace(__VA_ARGS__)

	#define OPS_PRINT(...) ::OPS::print(__VA__ARGS__)
	#define OPS_PRINT_INFO(...) ::OPS::Log::getClientLogger()->info(__VA_ARGS__)
	#define OPS_PRINT_ERROR(...) ::OPS::Log::geClienteLogger()->error(__VA_ARGS__)
	#define OPS_PRINT_WARN(...) ::OPS::Log::getClientLogger()->warn(__VA_ARGS__)
	#define OPS_PRINT_TRACE(...) ::OPS::Log::getClientLogger()->trace(__VA_ARGS__)
#else
	#define OPS_CORE_PRINT(...)
	#define OPS_CORE_PRINT_INFO(...)
	#define OPS_CORE_PRINT_ERROR(...)
	#define OPS_CORE_PRINT_WARN(...)
	#define OPS_CORE_PRINT_TRACE(...)

	#define OPS_PRINT(...)
	#define OPS_PRINT_INFO(...)
	#define OPS_PRINT_ERROR(...)
	#define OPS_PRINT_WARN(...)
	#define OPS_PRINT_TRACE(...)
#endif