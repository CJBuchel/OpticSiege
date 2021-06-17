#pragma once

#include <memory>
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

#include "OpticSiege/Core/Core.h"

namespace OPS {
	class Log {
	public:
		static void init();
		inline static std::shared_ptr<spdlog::logger> &getCoreLogger() {
			return _coreLogger;
		}
		
		inline static std::shared_ptr<spdlog::logger> &getClientLogger() {
			return _clientLogger;
		}

	private:
		static std::shared_ptr<spdlog::logger> _coreLogger;
		static std::shared_ptr<spdlog::logger> _clientLogger;
	};
}