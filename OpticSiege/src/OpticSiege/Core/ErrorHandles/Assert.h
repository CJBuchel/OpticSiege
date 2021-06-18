#pragma once

#include "OpticSiege/Core/Logging/Print.h"
#include <filesystem>

#ifdef OPS_ENABLE_ASSERTS

	// Alteratively we could use the same "default" message for both "WITH_MSG" and "NO_MSG" and
	// provide support for custom formatting by concatenating the formatting string instead of having the format inside the default message
	#define OPS_INTERNAL_ASSERT_IMPL(type, check, msg, ...) { if(!(check)) { OPS##type##PRINT_ERROR(msg, __VA_ARGS__); OPS_DEBUGBREAK(); } }
	#define OPS_INTERNAL_ASSERT_WITH_MSG(type, check, ...) OPS_INTERNAL_ASSERT_IMPL(type, check, "Assertion failed: {0}", __VA_ARGS__)
	#define OPS_INTERNAL_ASSERT_NO_MSG(type, check) OPS_INTERNAL_ASSERT_IMPL(type, check, "Assertion '{0}' failed at {1}:{2}", OPS_STRINGIFY_MACRO(check), std::filesystem::path(__FILE__).filename().string(), __LINE__)

	#define OPS_INTERNAL_ASSERT_GET_MACRO_NAME(arg1, arg2, macro, ...) macro
	#define OPS_INTERNAL_ASSERT_GET_MACRO(...) OPS_EXPAND_MACRO( OPS_INTERNAL_ASSERT_GET_MACRO_NAME(__VA_ARGS__, OPS_INTERNAL_ASSERT_WITH_MSG, OPS_INTERNAL_ASSERT_NO_MSG) )

	// Currently accepts at least the condition and one additional parameter (the message) being optional
	#define OPS_ASSERT(...) OPS_EXPAND_MACRO( OPS_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_, __VA_ARGS__) )
	#define OPS_CORE_ASSERT(...) OPS_EXPAND_MACRO( OPS_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_CORE_, __VA_ARGS__) )
#else
	#define OPS_ASSERT(...)
	#define OPS_CORE_ASSERT(...)
#endif
