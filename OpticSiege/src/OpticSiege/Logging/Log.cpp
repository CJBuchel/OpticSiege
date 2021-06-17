#include "Log.h"

namespace OPS {
	std::shared_ptr<spdlog::logger> Log::_coreLogger;
	std::shared_ptr<spdlog::logger> Log::_clientLogger;

	void Log::init() {
		spdlog::set_pattern("%^[%T] %n: %v%$");
		_coreLogger = spdlog::stderr_color_mt("OpticSiege");
		_coreLogger->set_level(spdlog::level::trace);

		_clientLogger = spdlog::stderr_color_mt("App");
		_clientLogger->set_level(spdlog::level::trace);
	}
}