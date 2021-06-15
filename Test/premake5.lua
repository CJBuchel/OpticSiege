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

	vpaths {
		["Header Files/*"] = { IncludeDir .. "**.h", IncludeDir .. "**.hpp" },
		["Source Files/*"] = { CppDir .. "*.c", CppDir .. ".cpp" }
	}

	includedirs {
		IncludeDir,
		"%{ROOT}/OpticSiege/src/include",
	}

	links {
		"OpticSiege"
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