#include "ops_pch.h"
#include "OpticSiege/Core/Application.h"

namespace OPS {
	Application::Application(const std::string &name, ApplicationArgs args) {
		_name = name;
		_args = args;
	}

	Application::~Application() {

	}

	void Application::run() {
		while (true) {
			
		}
	}
}