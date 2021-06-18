#include "ops_pch.h"
#include "OpticSiege/Core/Application.h"

namespace OPS {
	Application::Application(const std::string &name, ApplicationArgs args) {
		_name = name;
		_args = args;

		_window = std::unique_ptr<Window>(Window::create());
		_window->setEventCallBack(OPS_BIND_EVENT_FN(Application::onEvent));

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

			// update window
			_window->onUpdate();
		}
	}

	bool Application::onWindowClose(WindowCloseEvent &e) {
		_running = false;
		return true;
	}
}