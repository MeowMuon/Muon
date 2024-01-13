workspace "Muon"
	architecture "x64"
	configurations
	{
		"Debug",
		"Release",
		"Distribute"
	}

ENGINE_NAME = "Muon"
APP_NAME = "Sandbox"

MACRO_PREFIX = "MU"

ENGINE_INCLUDE_DIRS =
{
	"%{ENGINE_NAME}/src",
	"%{ENGINE_NAME}/vendor/spdlog/include"
}
APP_INCLUDE_DIRS =
{
	"%{ENGINE_NAME}/src",
	"%{ENGINE_NAME}/vendor/spdlog/include"
}

ENGINE_PCH = "mupch.h"
ENGINE_PCH_SRC = "%{ENGINE_NAME}/src/mupch.cpp"

OUT_FOLDER = "_bin"
OBJ_FOLDER = "_obj"

CONFIG_FOLDER = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

startproject (APP_NAME)

project (ENGINE_NAME)
	location "%{ENGINE_NAME}"
	kind "SharedLib"
	language "c++"

	targetdir "%{OUT_FOLDER}/%{CONFIG_FOLDER}/%{ENGINE_NAME}"
	objdir "%{OBJ_FOLDER}/%{CONFIG_FOLDER}/%{ENGINE_NAME}"

	pchheader (ENGINE_PCH)
	pchsource (ENGINE_PCH_SRC)

	files
	{
		"%{ENGINE_NAME}/src/**.h",
		"%{ENGINE_NAME}/src/**.cpp"
	}

	includedirs (ENGINE_INCLUDE_DIRS)

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		defines
		{
			"%{MACRO_PREFIX}_PLATFORM_WINDOWS",
			"%{MACRO_PREFIX}_BUILD_DLL"
		}

	filter "configurations:Debug"
		defines
		{
			"%{MACRO_PREFIX}_DEBUG"
		}
		symbols "On"

	filter "configurations:Release"
		defines
		{
			"%{MACRO_PREFIX}_RELEASE"
		}
		optimize "On"

	filter "configurations:Distribute"
		defines
		{
			"%{MACRO_PREFIX}_DISTRIBUTE"
		}
		optimize "On"

project (APP_NAME)
	location "%{APP_NAME}"
	kind "ConsoleApp"
	language "c++"

	targetdir "%{OUT_FOLDER}/%{CONFIG_FOLDER}/%{APP_NAME}"
	objdir "%{OBJ_FOLDER}/%{CONFIG_FOLDER}/%{APP_NAME}"

	files
	{
		"%{APP_NAME}/src/**.h",
		"%{APP_NAME}/src/**.cpp"
	}

	includedirs (APP_INCLUDE_DIRS)

	links
	{
		"%{ENGINE_NAME}"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		defines
		{
			"%{MACRO_PREFIX}_PLATFORM_WINDOWS"
		}
		prebuildcommands
		{
		}
		postbuildcommands
		{
			("{COPY} ../%{OUT_FOLDER}/%{CONFIG_FOLDER}/%{ENGINE_NAME}/%{ENGINE_NAME}.dll ../%{OUT_FOLDER}/%{CONFIG_FOLDER}/%{APP_NAME}")
		}

	filter "configurations:Debug"
		defines
		{
			"%{MACRO_PREFIX}_DEBUG"
		}
		symbols "On"

	filter "configurations:Release"
		defines
		{
			"%{MACRO_PREFIX}_RELEASE"
		}
		optimize "On"

	filter "configurations:Distribute"
		defines
		{
			"%{MACRO_PREFIX}_DISTRIBUTE"
		}
		optimize "On"
