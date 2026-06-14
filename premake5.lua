workspace "Kilo_Engine"
	architecture "x64"
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Kilo_Engine"
	location "Kilo_Engine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files 
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"
		flags { "multiprocessorcompile" }
		buildoptions { "/utf-8" } -- Explicit flag for compiler encoding

		defines 
		{
			"KL_PLATFORM_WINDOWS",
			"KILO_BUILD_DLL"
		}

	filter "system:windows"
		postbuildcommands
		{
			"{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Terreria"
		}

	filter "configurations:Debug"
		defines "KL_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "KL_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "KL_DIST"
		runtime "Release"
		optimize "On"


project "Terreria"
	location "Terreria"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files 
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Kilo_Engine/vendor/spdlog/include", -- Points out to the relative vendor directory
		"Kilo_Engine/src"
	}

	links
	{
		"Kilo_Engine"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"
		flags { "multiprocessorcompile" }
		buildoptions { "/utf-8" }

		defines 
		{
			"KL_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "KL_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "KL_RELEASE"
		runtime "Release"
		optimize "On"
