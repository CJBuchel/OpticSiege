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
	include "vendors/GLFW"
	include "vendors/GLAD"
group ""

include "Test"