project "Test"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir (BinDir .. "/%{prj.name}")
	objdir (ObjectDir .. "/%{prj.name}")


	-- file locations --
	local SrcDir = ROOT .. "Test/"
	local CppDir = SrcDir .. "cpp/"
	local IncludeDir = SrcDir .. "include/"

	files {
		IncludeDir .. "**.h", IncludeDir .. "**.hpp",
		CppDir .. "**.c", CppDir .. "**.cpp"
	}

	defines {
		"_CRT_SECURE_NO_WARNINGS",
		"GLFW_INCLUDE_NONE"
	}

	vpaths {
		["Header Files/*"] = { IncludeDir .. "**.h", IncludeDir .. "**.hpp" },
		["Source Files/*"] = { CppDir .. "*.c", CppDir .. ".cpp" }
	}

	includedirs {
		IncludeDir,
		"%{vendors.GLFW}"
	}

	links {
		"GLFW"
	}

	filter "system:windows"
		systemversion "latest"
		links { "opengl32.lib" }
		defines { "_WINDOWS" }

	
	-- Build Config --
	filter "configurations:Debug"
		defines "OPS_DEBUG"
		runtime "Debug"
		symbols "on"
	
	filter "configurations:Release"
		defines "OPS_Release"
		runtime "Release"
		optimize "on"