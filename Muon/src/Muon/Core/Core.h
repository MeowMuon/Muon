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
	#define MU_ASSERT_CORE(x, ...) { if (!(x)) { MU_LOG_CORE(LOG_ERROR, "Assertion failed:{0}", __VA_ARGS__);__debugbreak(); } }
	#define MU_ASSERT(x, ...) { if (!(x)) { MU_LOG(LOG_ERROR, "Assertion failed:{0}", __VA_ARGS__);__debugbreak(); } }
#else
	#define MU_ASSERT_CORE(x, ...)
	#define MU_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define MU_FORMAT(type, name, fmt) inline auto format(const type& name) { return fmt; }

#define MU_P(n) std::placeholders::_##n
#define MU_BIND_1P(fn, ptr) std::bind(&fn, ptr, MU_P(1))
#define MU_BIND_2P(fn, ptr) std::bind(&fn, ptr, MU_P(1), MU_P(2))
#define MU_BIND_3P(fn, ptr) std::bind(&fn, ptr, MU_P(1), MU_P(2), MU_P(3))
#define MU_BIND_4P(fn, ptr) std::bind(&fn, ptr, MU_P(1), MU_P(2), MU_P(3), MU_P(4))
#define MU_BIND_5P(fn, ptr) std::bind(&fn, ptr, MU_P(1), MU_P(2), MU_P(3), MU_P(4), MU_P(5))
#define MU_BIND_6P(fn, ptr) std::bind(&fn, ptr, MU_P(1), MU_P(2), MU_P(3), MU_P(4), MU_P(5), MU_P(6))
#define MU_BIND_7P(fn, ptr) std::bind(&fn, ptr, MU_P(1), MU_P(2), MU_P(3), MU_P(4), MU_P(5), MU_P(6), MU_P(7))
#define MU_BIND_8P(fn, ptr) std::bind(&fn, ptr, MU_P(1), MU_P(2), MU_P(3), MU_P(4), MU_P(5), MU_P(6), MU_P(7), MU_P(8))
#define MU_BIND_9P(fn, ptr) std::bind(&fn, ptr, MU_P(1), MU_P(2), MU_P(3), MU_P(4), MU_P(5), MU_P(6), MU_P(7), MU_P(8), MU_P(9))
