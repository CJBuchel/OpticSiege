project "IMGUI"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir (BinDir .. "/%{prj.name}")
	objdir (ObjectDir .. "/%{prj.name}")

	files {
		"imgui/imconfig.h",
		"imgui/imgui_demo.cpp",
		"imgui/imgui_draw.cpp",
		"imgui/imgui_internal.h",
		"imgui/imgui_tables.cpp",
		"imgui/imgui_widgets.cpp",
		"imgui/imgui.cpp",
		"imgui/imgui.h",
		"imgui/imstb_rectpack.h",
		"imgui/imstb_textedit.h",
		"imgui/imstb_truetype.h",

		-- Backend files --
		-- "imgui/backends/*.h", "imgui/backends/*.hpp",
		-- "imgui/backends/*.c", "imgui/backends/*.cpp"
		-- "imgui/backends/imgui_impl_glfw.h", "imgui/backends/imgui_impl_glfw.cpp",
		-- "imgui/backends/imgui_impl_opengl3.h", "imgui/backends/imgui_impl_opengl3.cpp"
	}

	filter "system:linux"
		pic "on"
		systemversion "latest"

	filter "system:windows"
		systemversion "latest"

	-- Config --
	filter "configurations:Debug"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		runtime "Release"
		optimize "on"