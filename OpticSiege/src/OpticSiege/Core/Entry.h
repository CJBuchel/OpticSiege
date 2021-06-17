#pragma once
#include "OpticSiege/Core/Core.h"
#include "OpticSiege/Core/Application.h"

extern OPS::Application *OPS::createApplication();

int main(int argc, char** argv) {
	/**
	* @TODO:
	* Create startup and ending procedured + loggers and handlers
	*/


	/**
	* Create application (only supports 1)
	*/
	auto app = OPS::createApplication();


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