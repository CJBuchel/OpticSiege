-- CONFIG FOR OPTIC SIEGE PREMAKE


ROOT = "%{wks.location}/" -- This directory style works on all platforms, not just unix
vendorLoc = "OpticSiege/vendors/"  -- Localized vendor dir (used only if you have root ./)
VendorDir = ROOT .. vendorLoc -- Non localized vendor dir. Used if you're inside a project or workspace
OutputDir = ROOT .. "build/" -- main output location for binaries
ProjectOutput = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}" -- output location for configured project
BinDir = OutputDir .. "bin/" .. ProjectOutput -- Directory output for binaries, project dependent
ObjectDir = OutputDir .. "bin-obj/" .. ProjectOutput -- Directory output for objects, project dependent



OpticSiegeDir = ROOT .. "OpticSiege/src/"