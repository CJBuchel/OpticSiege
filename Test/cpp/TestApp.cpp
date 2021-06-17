#include "TestApp.hpp"

class Test : public OPS::Application {
public:
	Test() : OPS::Application("Test App") {
	}

	~Test() {

	}
};

OPS_CREATE_APPLICATION(Test);