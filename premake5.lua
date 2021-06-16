-- Root Engine Workspace --
include "config.lua"
include "dependencies.lua"

newaction {
	trigger = "clean",
	description = "clean files and outputs",

	execute = function()
		print("Cleaning output folders...")
		os.rmdir(OutputDir)
		print("Done")
	end
}

filter "system:windows"
	defines { "OPS_PLATFORM_WINDOWS" }

--------------------
-- Main Workspace --
--------------------
workspace "OpticSiege"
	architecture "x86_64"
	startproject "Test"

	configurations {
		"Debug",
		"Release"
	}

	
	filter { "system:macosx", "action:gmake" }
		toolset "clang"

	filter {}

	flags {
		"MultiProcessorCompile"
	}
	
group "dependencies"
	include "OpticSiege/vendors/GLFW"
	include "OpticSiege/vendors/GLAD"
group ""

include "OpticSiege"
include "Test"