project "OpticSiege"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir (BinDir .. "/%{prj.name}")
	objdir (ObjectDir .. "/%{prj.name}")

	pchheader ("ops_pch.h")
	pchsource (OpticSiegeDir .. "ops_pch.cpp")


	files {
		-- Headers --
		OpticSiegeDir .. "**.h", OpticSiegeDir .. "**.hpp",

		-- Source Files --
		OpticSiegeDir .. "**.c", OpticSiegeDir .. "**.cpp",

		VendorDir .. "GLM/glm/glm/**.hpp", 
		VendorDir .. "GLM/glm/glm/**.inl"
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
		"%{vendors.GLAD}",
		"%{vendors.SPDLOG}",
		"%{vendors.IMGUI}",
		"%{vendors.GLM}"
	}

	links {
		"GLFW",
		"GLAD",
		"IMGUI",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"

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