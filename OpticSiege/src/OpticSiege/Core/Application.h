#pragma once

#include "OpticSiege/Core/Core.h"
#include "OpticSiege/Core/Window/Window.h"
#include "OpticSiege/Core/Events/AllEvents.h"
#include "OpticSiege/Core/Layers/LayerStack.h"

namespace OPS {
	struct ApplicationArgs {
		int count = 0;
		char **args = nullptr;
	};

	/**
	* Main application that runs inside engine
	*/
	class Application {
	public:
		Application(const std::string &name = "OpticSiege Application", ApplicationArgs args = ApplicationArgs());
		virtual ~Application();
		void run();

		/**
		* Get entire window (accessible)
		*/
		Window &getWindow() {
			return *_window;
		}

		/**
		* Staticly get application
		*/
		static Application &get() {
			return *_instance;
		}
		
		/**
		* On events (mouse, keyboard etc...)
		*/
		void onEvent(Event &e);

		/**
		* Layer control (push/pop)
		*/
		void pushLayer(Layer *layer);
		void pushOverlay(Layer *layer);

		/**
		* Getters
		*/
		std::string getName() {
			return _name;
		}

		ApplicationArgs getArgs() {
			return _args;
		}

	private:
		// Application
		bool onWindowClose(WindowCloseEvent &e);
		static Application *_instance;

		// window
		std::unique_ptr<Window> _window;
		bool _running = false;

		// application args
		std::string _name;
		ApplicationArgs _args;

		// layers
		LayerStack _layerStack;

	};

	Application *createApplication();
};

/**
* Main creator for OpticSiege public applications
*/
#define OPS_CREATE_APPLICATION(APP) OPS::Application *OPS::createApplication() { return new APP(); }