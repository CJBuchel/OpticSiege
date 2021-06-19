#pragma once

#include "spdlog/spdlog.h"
//#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/stdout_sinks.h"
#include "spdlog/fmt/ostr.h"

#include "OpticSiege/Core/Core.h"

namespace OPS {
	class Log {
	public:
		static void init(const std::string &appName);
		inline static std::shared_ptr<spdlog::logger> &getCoreLogger() {
			return _coreLogger;
		}
		
		inline static std::shared_ptr<spdlog::logger> &getClientLogger() {
			return _clientLogger;
		}

		inline static void setClientName(const std::string &name) {
			_clientLogger = spdlog::stderr_color_mt(name);
		}

	private:
		static std::shared_ptr<spdlog::logger> _coreLogger;
		static std::shared_ptr<spdlog::logger> _clientLogger;
	};
}