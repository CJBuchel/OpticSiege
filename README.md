# OpticSiege
Small game engine for low end visual games, mostly a side project. (AKA Wrapper lib currently for OpenGL designed imported as a DLL/Static Lib for game projects) in VS

## Dev steps for engine

1. Cross compatible building (PreMake, before trying to build the project).
	- I'm a sucker for cross compatibilty, and luckily openGL is a cross compatible library. But VS projects aren't known for their.... uhhhh, acceptance to other platforms :).
	- Setting up a premake project first is a better plan, get premake to build either makefiles or vs solutions depending on platforms. And allow the library to be built on any machine.

2. Window creation (OpenGL)
	- Create a wrapper and easy to access window creation solution, which can switch depending on platforms.

3. Event management (Keyboards etc...)
	- Event management solution, ( i 100% know their are issues between windows and linux in this case) that'l be fun.

4. Yet to be desided. I expect step 2 will take a bit longer than expected anyway....