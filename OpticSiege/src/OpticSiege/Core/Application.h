#pragma once

#include "OpticSiege/Core/Core.h"

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
		* Getters
		*/
		std::string getName() {
			return _name;
		}

		ApplicationArgs getArgs() {
			return _args;
		}

	private:
		std::string _name;
		ApplicationArgs _args;
	};

	Application *createApplication();
};

#define OPS_CREATE_APPLICATION(APP) OPS::Application *OPS::createApplication() { return new APP(); }