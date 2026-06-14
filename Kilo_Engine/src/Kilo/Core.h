#pragma once

#ifdef KL_PLATFORM_WINDOWS

	#ifdef KILO_BUILD_DLL

		#define KILO_API __declspec(dllexport)

	#else

		#define KILO_API __declspec(dllimport)

	#endif
#else 
	#error Kilo only supports Windows
#endif

#define BIT(x) (1 << x)

#ifdef _MSC_VER
#pragma warning(disable: 4251)
#endif