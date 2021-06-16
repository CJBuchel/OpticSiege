#pragma once

#include "Core.h"

namespace OPS {
	class Application {
	 public:
		Application();
		virtual ~Application();

		void run();
	};
};

/**
* Macro for app creation
*/
#define OPS_CREATE_APPLICATION()