#pragma once

#ifdef MU_PLATFORM_WINDOWS

#ifdef MU_BUILD_DLL
#define MUON_API __declspec(dllexport)
#else
#define MUON_API __declspec(dllimport)
#endif

#else

#error Platform is not properly defined!

#endif

#ifdef MU_ENABLE_ASSERT
	#define MU_ASSERT_CORE(x, ...) { if (!(x)) { MU_LOG(LOG_CORE_ERROR, "Assertion failed:{0}", __VA_ARGS__);__debugbreak(); } }
	#define MU_ASSERT(x, ...) { if (!(x)) { MU_LOG(LOG_ERROR, "Assertion failed:{0}", __VA_ARGS__);__debugbreak(); } }
#else
	#define MU_ASSERT_CORE(x, ...)	
	#define MU_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)
