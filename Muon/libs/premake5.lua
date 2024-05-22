project "Libraries"
	location ""

	kind "StaticLib"
	language "C++"
	staticruntime "off"
	warnings "off"

	targetdir "%{OUT_FOLDER}/%{CONFIG_FOLDER}/%{prj.name}"
	objdir "%{OBJ_FOLDER}/%{CONFIG_FOLDER}/%{prj.name}"

	files
	{
		"%{prj.location}/GLFW/src/**.h",
		"%{prj.location}/GLFW/src/**.c",

		"%{prj.location}/Glad/src/**.h",
		"%{prj.location}/Glad/src/**.c",

		"%{prj.location}/ImGui/*.h",
		"%{prj.location}/ImGui/*.cpp"
	}

	removefiles
	{

	}

	includedirs
	{
		"%{prj.location}/GLFW/include",
		
		"%{prj.location}/Glad/include"
	}
	
	filter "system:Windows"
		systemversion "latest"
		defines
		{
			"_GLFW_WIN32",
			"_CRT_SECURE_NO_WARNINGS"
		}

	filter "system:Linux"
		pic "On"
		systemversion "latest"
		defines
		{
			"_GLFW_X11"
		}

	filter "system:MacOSx"
		pic "On"
		defines
		{
			"_GLFW_COCOA"
		}

	filter "configurations:Debug"
		runtime "debug"
		optimize "off"
		symbols "on"

	filter "configurations:Release"
		runtime "release"
		optimize "speed"
		symbols "on"

	filter "configurations:Distribute"
		runtime "release"
		optimize "speed"
		symbols "off"
