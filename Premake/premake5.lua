-- Root Engine Project --

local ROOT = "../" -- This directory style works on all platforms, not just unix
local SolDir = ROOT .. "Solution/" -- Directory for sultion files and project files for VS

------------------------------------------
---------- [ WORKSPACE CONFIG ] ----------
------------------------------------------

workspace "OpticSiege"										-- Solution name
	configurations { "Debug", "Release" } 	-- General config mode in VS
	platforms			 { "x64", "x32" }					-- Dropdown platforms in VS
	location (SolDir)												-- Location for solution file

	-- _ACTION -> argument passed in when running premake
	local project_action = "UNDEFINED"
	if _ACTION ~= null then project_action = _ACTION end

	------------------------------
	-- [ CLEAN OUTPUT FOLDERS ] --
	------------------------------
	newaction {
		trigger = "clean",
		description = "clean software",
		
		execute = function()
			print("Cleaning the Solution folder...")
			os.rmdir(ROOT .. "./Solution")
			print("done.")
		end
	}

	--------------------------------
	-- [ COMPILER/LINKER CONFIG ] --
	--------------------------------

	flags "FatalWarnings" -- Warnings count as errors
	warnings "Extra"

	-- see 'filter' in wiki pages
	filter "configurations:Debug" defines { "DEBUG" } symbols "On"
	filter "configurations:Release" defines { "RELEASE" } symbols "On"

	filter { "platforms:x32" } architecture "x86"
	filter { "platforms:x64" } architecture "x64"

	-- building in windows/VS --
	filter { "system:windows", "action:vs" }
		cppdialect "C++20"
		flags { "MultiProcessorCompile", "NoMinimalRebuild" }
		linkoptions { "/ignore:4099" } -- ignore library pdb warnings in debug

	-- building in linux/makefiles --
	filter { "action:gmake" }
		cppdialect "C++20"

	-- building in mac/makefiles --
	filter { "system:macosx", "action:gmake" }
		cppdialect "C++20"
		toolset "clang"

	filter {} -- clear filter when not needed

	------------------------
	-- [ PROJECT CONFIG ] --
	------------------------
	project "Test"
		kind "ConsoleApp" -- "WindowApp" removes console
		language "C++"
		location (SolDir)
		targetdir (SolDir .. "bin_%{cfg.buildcfg}_%{cfg.platform}") -- output binary location
		targetname "test" -- name of executable

		-----------------------------
		-- [ PROJECT FILE CONFIG ] --
		-----------------------------
		local SrcDir = ROOT .. "test/"
		local CppDir = SrcDir .. "cpp/"
		local IncludeDir = SrcDir .. "include/"


		-- Files --
		files {
			IncludeDir .. "**.h", IncludeDir .. "**.hpp", -- Headers
			CppDir .. "**.c", CppDir .. "**.cpp", CppDir .. "**.tpp", -- Src
		}

		-- Exclude from build --
		filter { "files:**.tpp" }
			flags { "ExcludeFromBuild" }

		filter {} -- clear filter

		-- setup VS filters (virtual folders)
		vpaths {
			["Header Files/*"] = { IncludeDir .. "**.h", IncludeDir .. "**.hxx", IncludeDir .. "**.hpp" },
			["Source Files/*"] = { CppDir .. "**.c", CppDir .. "**.cxx", CppDir .. "**.cpp" },
		}

		-- header locations
		includedirs {
			IncludeDir -- Allow #includable from dir
		}
		
		------------------------------
		-- [ PROJECT DEPENDENCIES ] --
		------------------------------
		libdirs {
			-- add dependencies (dirs) here
		}

		links {
			-- add dependencies (libs) here
		}