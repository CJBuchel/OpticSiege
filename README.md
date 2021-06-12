# OpticSiege
Small game engine for low end visual games, mostly a side project. (AKA Wrapper lib currently for OpenGL designed imported as a DLL/Static Lib for game projects) in VS


## Setup for building

1. Build setup
	- This project uses premake to setup build for local operating system. To use premake first link the Premake/bin folder to you system path, or copy the folder to a different location for your own convenienve (unless you already have premake installed and linked)

	- Once binaries are linked, in cmd/terminal run `premake5 vs2019` to build solution and project files (they will apear in `Solution/` folder)

	- For linux/mac run `./premake5 gmake` or `./premake5_mac gmake` instead.



	### (If you already has premake setup and linked, check the binary names, as they may not match. You might need to run `./premake5 gmake` or just `./premake gmake`)

2. Cleaning build
	- Run `premake5 clean` to clean out solution folder (`./premake5 clean` for mac/linux)