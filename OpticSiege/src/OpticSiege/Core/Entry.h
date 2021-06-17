#pragma once
#include "OpticSiege/Core/Core.h"
#include "OpticSiege/Logging/Print.h"
#include "OpticSiege/Core/Application.h"

extern OPS::Application *OPS::createApplication();

int main(int argc, char** argv) {
	/**
	* @TODO:
	* Create startup and ending procedured + loggers and handlers
	*/


	OPS::Log::init("[Application Pre-Startup]");

	OPS_CORE_PRINT_ERROR("YEET THE CHILD");
	OPS_PRINT_INFO("...no, don't yeet the child");

	/**
	* Create application (only supports 1)
	*/
	auto app = OPS::createApplication();
	OPS::Log::setClientName("[" + app->getName() + "]");

	OPS_CORE_PRINT_ERROR("YEET THE CHILD");
	OPS_PRINT_INFO("...no, don't yeet the child");


	/**
	* Super loop runner
	*/
	app->run();


	/**
	* App cleanup
	*/
	delete app;
	return 0;
}