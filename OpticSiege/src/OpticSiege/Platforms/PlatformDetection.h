#pragma once

#ifdef _WIN32 // if windows
	#ifdef _WIN64
		#define OPS_PLATFORM_WINDOWS
		#define _USE_OPENGL
	#else
		#error "[OpticSiege]: x86 platform detected. Use x64"
	#endif

#elif defined(__APPLE__) || defined(__MACH__)
	#include <TargetConditionals.h>

	#if TARGET_IPHONE_SIMULATOR == 1
		#error "IOS simulator is not supported!"
	#elif TARGET_OS_IPHONE == 1
		#define OPS_PLATFORM_IOS
		#error "IOS is not supported!"
	#elif TARGET_OS_MAC == 1
		#define OPS_PLATFORM_MACOS
	#else
		#error "Unknown Apple platform!"
	#endif


#elif defined(__ANDROID__)
	#define OPS_PLATFORM_ANDROID
	#error "Android is not supported"

#elif defined(__linux__)
	#define OPS_PLATFORM_LINUX

#else 
	#error "Unknown platform!"
#endif