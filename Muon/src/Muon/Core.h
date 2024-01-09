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