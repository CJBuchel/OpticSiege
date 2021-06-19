#include "ops_pch.h"
#include "OpticSiege/Core/Application.h"

#include <glad/glad.h>

#include "OpticSiege/Core/Input/Input.h"

#include <glm/glm.hpp>

namespace OPS {
	Application *Application::_instance = nullptr;


	Application::Application(const std::string &name, ApplicationArgs args) {
		OPS_CORE_ASSERT(!_instance, "An application already exists. Cannot create another");
		_instance = this;
		_name = name;
		_args = args;

		// Abstract window
		_window = std::unique_ptr<Window>(Window::create());
		_window->setEventCallBack(OPS_BIND_EVENT_FN(Application::onEvent));

		// ImGui
		_imGuiLayer = new ImGuiLayer();
		pushOverlay(_imGuiLayer);

		/**
		* Set the runner
		*/
		_running = true;
	}

	Application::~Application() {

	}

	void Application::pushLayer(Layer *layer) {
		_layerStack.pushLayer(layer);
		layer->onAttach();
	}

	void Application::pushOverlay(Layer *layer) {
		_layerStack.popOverlay(layer);
		layer->onAttach();
	}

	void Application::onEvent(Event &e) {
		EventDispatcher dispatcher(e);
		dispatcher.dispatch<WindowCloseEvent>(OPS_BIND_EVENT_FN(Application::onWindowClose));
		OPS_CORE_PRINT_TRACE("{0}", e);

		// layerstack event control
		for (auto it = _layerStack.end(); it != _layerStack.begin();) {
			(*--it)->onEvent(e);
			if (e.handled) {
				break;
			}
		}
	}

	void Application::run() {
		while (_running) {

			// Update layers
			for (Layer *layer : _layerStack) {
				layer->onUpdate();
			}

			auto [x, y] = Input::getMousePos();
			OPS_CORE_PRINT_TRACE("{0}, {1}", x, y);

			// imgui render
			_imGuiLayer->begin();
			for (Layer *layer : _layerStack) {
				layer->onImGuiRender();
			}
			_imGuiLayer->end();

			// update window
			_window->onUpdate();
		}
	}

	bool Application::onWindowClose(WindowCloseEvent &e) {
		_running = false;
		return true;
	}
}