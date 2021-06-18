#include "ops_pch.h"
#include "OpticSiege/Platforms/Windows/WinPlat_Window.h"

#include "OpticSiege/Core/Events/ApplicationEvent.h"
#include "OpticSiege/Core/Events/KeyEvent.h"
#include "OpticSiege/Core/Events/MouseEvent.h"


namespace OPS {
	static bool _GLFW_INITIALIZED = false;
	static bool _GLAD_INITIALIZED = false;

	static void GLFWErrorCallBack(int error, const char *description) {
		OPS_CORE_PRINT_ERROR("GLFW Error ({0}, {1}):", error, description);
	}

	Window *Window::create(const WindowConfig &config) {
		return new WinPlat_Window(config);
	}

	WinPlat_Window::WinPlat_Window(const WindowConfig &config) {
		init(config);
	}

	WinPlat_Window::~WinPlat_Window() {
		shutdown();
	}

	void WinPlat_Window::init(const WindowConfig &config) {
		_data.title = config.title;
		_data.width = config.width;
		_data.height = config.height;

		OPS_CORE_PRINT_INFO("Creating Window {0}: ({1}, {2})", config.title, config.width, config.height);

		if (!_GLFW_INITIALIZED) {
			int success = glfwInit();
			OPS_CORE_ASSERT(success, "Could not initialize GLFW");
			glfwSetErrorCallback(GLFWErrorCallBack);
			_GLFW_INITIALIZED = true;
		}

		OPS_CORE_PRINT_INFO("GLFW initialized");

		_window = glfwCreateWindow((int)config.width, (int)config.height, _data.title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(_window);
		glfwSetWindowUserPointer(_window, &_data);
		setVSync(true);

		if (!_GLAD_INITIALIZED) {
			int success = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
			OPS_CORE_ASSERT(success, "Could not initialize GLAD");

			_GLAD_INITIALIZED = true;
		}

		/**
		*	Set GLFW callbacks
		*/
		glfwSetWindowSizeCallback(_window, [](GLFWwindow *window, int width, int height) {
			WindowData &data = *(WindowData *)glfwGetWindowUserPointer(window);
			data.width = width;
			data.height = height;

			WindowResizeEvent event(width, height);
			data.eventCallBack(event);
		});

		glfwSetWindowCloseCallback(_window, [](GLFWwindow *window) {
			WindowData &data = *(WindowData *)glfwGetWindowUserPointer(window);
			WindowCloseEvent event;
			data.eventCallBack(event);
		});

		glfwSetKeyCallback(_window, [](GLFWwindow *window, int key, int scancode, int action, int mods) {
			WindowData &data = *(WindowData *)glfwGetWindowUserPointer(window);
			switch (action) {
				case GLFW_PRESS:
				{
					KeyPressedEvent event(key, 0);
					data.eventCallBack(event);
					break;
				}

				case GLFW_RELEASE:
				{
					KeyReleasedEvent event(key);
					data.eventCallBack(event);
					break;
				}

				case GLFW_REPEAT:
				{
					KeyPressedEvent event(key, 1);
					data.eventCallBack(event);
					break;
				}
			}
		});

		glfwSetMouseButtonCallback(_window, [](GLFWwindow *window, int button, int action, int modes) {
			WindowData &data = *(WindowData *)glfwGetWindowUserPointer(window);

			switch (action) {
				case GLFW_PRESS:
				{
					MouseButtonPressedEvent event(button);
					data.eventCallBack(event);
					break;
				}

				case GLFW_RELEASE:
				{
					MouseButtonReleasedEvent event(button);
					data.eventCallBack(event);
					break;
				}
			}
		});

		glfwSetScrollCallback(_window, [](GLFWwindow *window, double xOffset, double yOffset) {
			WindowData &data = *(WindowData *)glfwGetWindowUserPointer(window);

			MouseScrolledEvent event((float)xOffset, (float)yOffset);
			data.eventCallBack(event);
		});

		glfwSetCursorPosCallback(_window, [](GLFWwindow *window, double xPos, double yPos) {
			WindowData &data = *(WindowData *)glfwGetWindowUserPointer(window);

			MouseMovedEvent event((float)xPos, (float)yPos);
			data.eventCallBack(event);
		});
	}

	void WinPlat_Window::shutdown() {
		glfwDestroyWindow(_window);
	}

	void WinPlat_Window::onUpdate() {
		glfwPollEvents();
		glfwSwapBuffers(_window);
	}

	void WinPlat_Window::setVSync(bool enabled) {
		if (enabled) {
			glfwSwapInterval(1);
		} else {
			glfwSwapInterval(0);
		}
		_data.vSync = enabled;
	}

	bool WinPlat_Window::isVSync() const {
		return _data.vSync;
	}
}