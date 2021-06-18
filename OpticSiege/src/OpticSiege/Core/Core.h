#pragma once

#include "OpticSiege/Platforms/PlatformDetection.h"
#include "OpticSiege/Core/ErrorHandles/ErrorHandles.h"

#include <memory>

#ifdef OPS_DEBUG
	#if defined(OPS_PLATFORM_WINDOWS)
		#define OPS_DEBUGBREAK() __debugbreak()
	#elif defined(OPS_PLATFORM_LINUX)
		#include <signal.h>
		#define OPS_DEBUGBREAK() raise(SIGTRAP)
	#else
		#error "Platform doesn't support debugbreak yet!"
	#endif
	#define OPS_ENABLE_ASSERTS
#else
	#define OPS_DEBUGBREAK()
#endif

#define OPS_EXPAND_MACRO(x) x
#define OPS_STRINGIFY_MACRO(x) #x

#define BIT(x) (1 << x)

#define OPS_BIND_EVENT_FN(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }

namespace OPS {

	template<typename T>
	using Scope = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args) {
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Ref = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args) {
		return std::make_shared<T>(std::forward<Args>(args)...);
	}

}