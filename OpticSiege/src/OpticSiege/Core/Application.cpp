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
		WindowResizeEvent e(1280, 720);

		OPS_CORE_PRINT_TRACE(e);
		while (true) {
			
		}
	}
}