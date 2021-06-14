-- CONFIG FOR OPTIC SIEGE PREMAKE


ROOT = "%{wks.location}/" -- This directory style works on all platforms, not just unix
VendorDir = ROOT .. "vendors/"
OutputDir = ROOT .. "build/" -- main output location for binaries
ProjectOutput = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}" -- output location for configured project
BinDir = OutputDir .. "bin/" .. ProjectOutput -- Directory output for binaries, project dependent
ObjectDir = OutputDir .. "bin-obj/" .. ProjectOutput -- Directory output for objects, project dependent