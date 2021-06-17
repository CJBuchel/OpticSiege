#pragma once

#include <iostream>
#include "OpticSiege/Core/Core.h"

namespace OPS {
	struct ApplicationArgs {
		int count = 0;
		char **args = nullptr;
	};

	class Application {
	public:
		Application(const std::string &name = "OpticSiege Application", ApplicationArgs args = ApplicationArgs());
		virtual ~Application();
		void run();

	private:
		std::string _name;
		ApplicationArgs _args;
	};

	Application *createApplication();
};

#define OPS_CREATE_APPLICATION(APP) OPS::Application *OPS::createApplication() { return new APP(); }