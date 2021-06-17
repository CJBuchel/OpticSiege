#pragma once

#ifdef OPS_PLATFORM_WINDOWS // if windows
 	#ifdef OPS_BUILD_DLL // if build as DLL
 		#define OPS_API __declspec(dllexport)
 	#else
 		#define OPS_API __declspec(dllimport)
 	#endif
 #else
 	#error windows only app (for now)
 #endif