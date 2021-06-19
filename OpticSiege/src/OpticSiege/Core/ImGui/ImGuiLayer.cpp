#include "ops_pch.h"
#include "OpticSiege/Core/ImGui/ImGuiLayer.h"

#include <imgui.h>

#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>

#include "OpticSiege/Core/Application.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace OPS {

	ImGuiLayer::ImGuiLayer() : Layer("ImGuiLayer") {
		OPS_CORE_PRINT_WARN("ImGu layer Created");
	}

	ImGuiLayer::~ImGuiLayer() {
		OPS_CORE_PRINT_WARN("ImGui Layer Destroyed");
	}


	void ImGuiLayer::onAttach() {
		// Setup
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGuiIO &io = ImGui::GetIO();
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;

		io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
		io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;

		ImGui::StyleColorsDark();

		ImGuiStyle &style = ImGui::GetStyle();
		if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable) {
			style.WindowRounding = 0.0f;
			style.Colors[ImGuiCol_WindowBg].w = 1.0f;
		}

		Application &app = Application::get();
		GLFWwindow *window = static_cast<GLFWwindow *>(app.getWindow().getNativeWindow());

		ImGui_ImplGlfw_InitForOpenGL(window, true);
		ImGui_ImplOpenGL3_Init("#version 410");
	}

	void ImGuiLayer::onDetach() {
		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();
		ImGui::DestroyContext();
	}

	void ImGuiLayer::begin() {
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
	}

	void ImGuiLayer::end() {
		ImGuiIO &io = ImGui::GetIO();
		Application &app = Application::get();
		io.DisplaySize = ImVec2(app.getWindow().getWidth(), app.getWindow().getHeight());

		// Rendering
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable) {
			GLFWwindow *backup_current_context = glfwGetCurrentContext();
			ImGui::UpdatePlatformWindows();
			ImGui::RenderPlatformWindowsDefault();
			glfwMakeContextCurrent(backup_current_context);
		}
	}

	void ImGuiLayer::onImGuiRender() {
		static bool show = true;
		ImGui::ShowDemoWindow(&show);
	}
}