-- Root Engine Workspace --
include "config.lua"
include "dependencies.lua"

workspace "OpticSiege"
	architecture "x86_64"
	startproject "Test"

	configurations {
		"Debug",
		"Release"
	}

	flags {
		"MultiProcessorCompile"
	}

group "dependencies"
	include "vendors/GLFW"
	include "vendors/GLAD"
group ""

include "Test"