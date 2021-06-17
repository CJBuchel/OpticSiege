project "OpticSiege"
	kind "SharedLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "On"

	targetdir (BinDir .. "/%{prj.name}")
	objdir (ObjectDir .. "/%{prj.name}")

	-- pchheader "ops_pch.hpp"
	-- pchsource "src/cpp/ops_pch.cpp"


	files {
		-- Headers --
		OpticSiegeDir .. "**.h", OpticSiegeDir .. "**.hpp",

		-- Source Files --
		OpticSiegeDir .. "**.c", OpticSiegeDir .. "**.cpp"
	}

	defines {
		"_CRT_SECURE_NO_WARNINGS",
		"GLFW_INCLUDE_NONE"
	}

	vpaths {
		["Header Files/*"] = {
			OpticSiegeDir .. "**.h", OpticSiegeDir .. "**.hpp" 
		},

		["Source FIles/*"] = {  
			OpticSiegeDir .. "**.c", OpticSiegeDir .. "**.cpp" 
		}
	}

	includedirs {
		OpticSiegeDir,
		"%{vendors.GLFW}",
		"%{vendors.GLAD}"
	}

	links {
		"GLFW",
		"GLAD"
	}

	postbuildcommands {
		("{COPY} %{cfg.buildtarget.relpath} " .. BinDir .. "/Test")
	}

	filter "system:windows"
		systemversion "latest"
		links { "opengl32.lib" }
		defines { "OPS_PLATFORM_WINDOWS", "OPS_BUILD_DLL" }

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