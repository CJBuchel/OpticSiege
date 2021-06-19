#include "ops_pch.h"
#include "OpticSiege/Platforms/Windows/WinPlat_Window.h"

#include "OpticSiege/Core/Application.h"

#include <GLFW/glfw3.h>
#include "WinPlat_Input.h"

namespace OPS {

	Input *Input::_instance = new WinPlat_Input();

	bool WinPlat_Input::isKeyPressedImpl(int keycode) {
		auto window = static_cast<GLFWwindow*>(Application::get().getWindow().getNativeWindow());
		auto state = glfwGetKey(window, keycode);

		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}

	bool WinPlat_Input::isMouseButtonPressedImpl(int button) {
		auto window = static_cast<GLFWwindow *>(Application::get().getWindow().getNativeWindow());
		auto state = glfwGetMouseButton(window, button);

		return state == GLFW_PRESS;
	}

	std::pair<float, float> WinPlat_Input::getMousePosImpl() {
		auto window = static_cast<GLFWwindow *>(Application::get().getWindow().getNativeWindow());
		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);
		return { (float)xpos, (float)ypos };
	}

	float WinPlat_Input::getMouseXImpl() {
		return getMousePos().first;
	}

	float WinPlat_Input::getMouseYImpl() {
		return getMousePos().second;
	}
}