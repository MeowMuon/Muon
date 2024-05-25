-- Project configurations:
ENGINE_NAME = "Muon"
APP_NAME = "Sandbox"

MACRO_PREFIX = "MU"

OUT_FOLDER = "%{wks.location}/_bin"
OBJ_FOLDER = "%{wks.location}/_obj"

CONFIG_FOLDER = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

ENGINE_PCH = "mupch.h"
ENGINE_PCH_SRC = "%{ENGINE_NAME}/src/mupch.cpp"

-- Include directories
INCLUDE_DIRS = {}
INCLUDE_DIRS["MuonSrc"] = "%{wks.location}/%{ENGINE_NAME}/src"
INCLUDE_DIRS["spdlog"] = "%{wks.location}/%{ENGINE_NAME}/libs/spdlog/include"
INCLUDE_DIRS["GLFW"] = "%{wks.location}/%{ENGINE_NAME}/libs/GLFW/include"
INCLUDE_DIRS["Glad"] = "%{wks.location}/%{ENGINE_NAME}/libs/Glad/include"
INCLUDE_DIRS["ImGui"] = "%{wks.location}/%{ENGINE_NAME}/libs/ImGui"
INCLUDE_DIRS["glm"] = "%{wks.location}/%{ENGINE_NAME}/libs/glm"

ENGINE_INCLUDE_DIRS =
{
	INCLUDE_DIRS["MuonSrc"],
	INCLUDE_DIRS["spdlog"],
	INCLUDE_DIRS["GLFW"],
	INCLUDE_DIRS["Glad"],
	INCLUDE_DIRS["ImGui"],
	INCLUDE_DIRS["glm"]
}
APP_INCLUDE_DIRS =
{
	INCLUDE_DIRS["MuonSrc"],
	INCLUDE_DIRS["spdlog"],
	INCLUDE_DIRS["glm"]
}

-- Library directories
LIBRARY_DIRS = {}

ENGINE_LIBRARY_DIRS =
{
}
APP_LIBRARY_DIRS =
{
}

-- Library files
LIBRARY_FILES = {}

ENGINE_LIBRARY_FILES =
{
	"Libraries"
}
APP_LIBRARY_FILES =
{
	"%{ENGINE_NAME}"
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
include (ENGINE_NAME .. "/libs")

--Engine
project (ENGINE_NAME)
	--==General Information==--
	location "%{ENGINE_NAME}"
	kind "SharedLib"
	language "C++"

	targetdir "%{OUT_FOLDER}/%{CONFIG_FOLDER}/%{ENGINE_NAME}"
	objdir "%{OBJ_FOLDER}/%{CONFIG_FOLDER}/%{ENGINE_NAME}"

	pchheader (ENGINE_PCH)
	pchsource (ENGINE_PCH_SRC)

	files
	{
		"%{ENGINE_NAME}/src/**.h",
		"%{ENGINE_NAME}/src/**.c",
		"%{ENGINE_NAME}/src/**.hpp",
		"%{ENGINE_NAME}/src/**.cpp"
	}

	includedirs (ENGINE_INCLUDE_DIRS)
	libdirs (ENGINE_LIBRARY_DIRS)
	links (ENGINE_LIBRARY_FILES)

	--==Platforms==--
	filter "system:Windows"
		cppdialect "C++17"
		staticruntime "off"
		systemversion "latest"
		defines
		{
			"%{MACRO_PREFIX}_PLATFORM_WINDOWS",
			"%{MACRO_PREFIX}_BUILD_DLL",

			"GLFW_INCLUDE_NONE"
		}
		prebuildcommands
		{
			("{RMDIR} %{OUT_FOLDER}/%{CONFIG_FOLDER}/%{ENGINE_NAME}")
		}
		postbuildcommands
		{
		}

	--==Configurations==--
	filter "configurations:Debug"
		defines
		{
			"%{MACRO_PREFIX}_DEBUG",
			"%{MACRO_PREFIX}_ENABLE_ASSERT"
		}
		runtime "debug"
		optimize "off"
		symbols "on"

	filter "configurations:Release"
		defines
		{
			"%{MACRO_PREFIX}_RELEASE"
		}
		runtime "release"
		optimize "on"
		symbols "on"

	filter "configurations:Distribute"
		defines
		{
			"%{MACRO_PREFIX}_DISTRIBUTE"
		}
		runtime "release"
		optimize "speed"
		symbols "off"

--Sandbox
project (APP_NAME)
	--==General Information==--
	location "%{APP_NAME}"
	kind "ConsoleApp"
	language "C++"

	targetdir "%{OUT_FOLDER}/%{CONFIG_FOLDER}/%{APP_NAME}"
	objdir "%{OBJ_FOLDER}/%{CONFIG_FOLDER}/%{APP_NAME}"

	files
	{
		"%{APP_NAME}/src/**.h",
		"%{APP_NAME}/src/**.cpp"
	}

	includedirs (APP_INCLUDE_DIRS)
	libdirs (APP_LIBRARY_DIRS)
	links (APP_LIBRARY_FILES)

	--==Platforms==--
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "off"
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

	--==Configurations==--
	filter "configurations:Debug"
		defines
		{
			"%{MACRO_PREFIX}_DEBUG",
			"%{MACRO_PREFIX}_ENABLE_ASSERT"
		}
		symbols "on"
		runtime "debug"

	filter "configurations:Release"
		defines
		{
			"%{MACRO_PREFIX}_RELEASE"
		}
		optimize "on"
		runtime "release"

	filter "configurations:Distribute"
		defines
		{
			"%{MACRO_PREFIX}_DISTRIBUTE"
		}
		optimize "on"
		runtime "release"
