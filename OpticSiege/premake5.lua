project "OpticSiege"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "off"

	targetdir (BinDir .. "/%{prj.name}")
	objdir (ObjectDir .. "/%{prj.name}")

	pchheader "ops_pch.hpp"
	pchsource "src/cpp/ops_pch.cpp"

	-- File Locations --
	local SrcDir = ROOT .. "OpticSiege/"
	local CppDir = SrcDir .. "src/cpp/"
	local IncludeDir = SrcDir .. "src/include/"

	files {
		IncludeDir .. "**.h", IncludeDir .. "**.hpp",
		CppDir .. "**.c", CppDir .. "**.cpp", CppDir .. "**.h", CppDir .. "**.hpp"
	}

	defines {
		"_CRT_SECURE_NO_WARNINGS",
		"GLFW_INCLUDE_NONE"
	}

	vpaths {
		["Header Files/*"] = { IncludeDir .. "**.h", IncludeDir .. "**.hpp" },
		["Source FIles/*"] = { CppDir .. "*.c", CppDir .. ".cpp" }
	}

	includedirs {
		IncludeDir,
		"%{vendors.GLFW}",
		"%{vendors.GLAD}"
	}

	links {
		"GLFW",
		"GLAD"
	}

	filter "system:windows"
		systemversion "latest"
		links { "opengl32.lib" }
		defines { "_WINDOWS" }

	filter "system:linux"
		systemversion "latest"
		links { "dl", "pthread" }
		defines { "_X11" }

	
	-- Build Config --
	filter "configurations:Debug"
		defines "OPS_DEBUG"
		runtime "Debug"
		symbols "on"
	
	filter "configurations:Release"
		defines "OPS_RELEASE"
		runtime "Release"
		optimize "on"