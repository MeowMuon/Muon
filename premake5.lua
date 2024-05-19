-- Project configurations:
ENGINE_NAME = "Muon"
APP_NAME = "Sandbox"

MACRO_PREFIX = "MU"

ENGINE_PCH = "mupch.h"
ENGINE_PCH_SRC = "%{ENGINE_NAME}/src/mupch.cpp"

OUT_FOLDER = "%{wks.location}/_bin"
OBJ_FOLDER = "%{wks.location}/_obj"

CONFIG_FOLDER = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories
INCLUDE_DIRS = {}
INCLUDE_DIRS["spdlog"] = "%{ENGINE_NAME}/vendor/spdlog/include"
INCLUDE_DIRS["GLFW"] = "%{ENGINE_NAME}/vendor/GLFW/include"

ENGINE_INCLUDE_DIRS =
{
	INCLUDE_DIRS["spdlog"],
	INCLUDE_DIRS["GLFW"],
	"%{ENGINE_NAME}/src"
}
APP_INCLUDE_DIRS =
{
	INCLUDE_DIRS["spdlog"],
	"%{ENGINE_NAME}/src"
}

-- Library directories
LIBRARY_DIRS = {}

ENGINE_LIBRARY_DIRS =
{
}

-- Library files
LIBRARY_FILES = {}

ENGINE_LIBRARY_FILES =
{
	"GLFW"
}

-- ==========	Workspace	==========
workspace (ENGINE_NAME)
	architecture "x64"
	configurations
	{
		"Debug",
		"Release",
		"Distribute"
	}
	startproject (APP_NAME)

-- ==========	Projects	==========
include (ENGINE_NAME .. "/vendor/_premake_/GLFW")

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

	libdirs (ENGINE_LIBRARY_DIRS)
	links (ENGINE_LIBRARY_FILES)

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "Off"
		systemversion "latest"
		defines
		{
			"%{MACRO_PREFIX}_PLATFORM_WINDOWS",
			"%{MACRO_PREFIX}_BUILD_DLL"
		}
		prebuildcommands
		{
			("{RMDIR} %{OUT_FOLDER}/%{CONFIG_FOLDER}/%{ENGINE_NAME}")
		}
		postbuildcommands
		{
		}

	filter "configurations:Debug"
		defines
		{
			"%{MACRO_PREFIX}_DEBUG",
			"%{MACRO_PREFIX}_ENABLE_ASSERT"
		}
		symbols "On"
		runtime "Debug"

	filter "configurations:Release"
		defines
		{
			"%{MACRO_PREFIX}_RELEASE"
		}
		optimize "On"
		runtime "Release"

	filter "configurations:Distribute"
		defines
		{
			"%{MACRO_PREFIX}_DISTRIBUTE"
		}
		optimize "On"
		runtime "Release"

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
		staticruntime "Off"
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
			("{COPY} %{OUT_FOLDER}/%{CONFIG_FOLDER}/%{ENGINE_NAME}/%{ENGINE_NAME}.dll %{OUT_FOLDER}/%{CONFIG_FOLDER}/%{APP_NAME}")
		}

	filter "configurations:Debug"
		defines
		{
			"%{MACRO_PREFIX}_DEBUG",
			"%{MACRO_PREFIX}_ENABLE_ASSERT"
		}
		symbols "On"
		runtime "Debug"

	filter "configurations:Release"
		defines
		{
			"%{MACRO_PREFIX}_RELEASE"
		}
		optimize "On"
		runtime "Release"

	filter "configurations:Distribute"
		defines
		{
			"%{MACRO_PREFIX}_DISTRIBUTE"
		}
		optimize "On"
		runtime "Release"
