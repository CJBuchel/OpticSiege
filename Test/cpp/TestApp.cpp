#include "TestApp.hpp"

class ExampleLayer : public OPS::Layer {
public:
	ExampleLayer() : Layer("Example Layer") {
		OPS_PRINT_INFO("Example layer created");
	}

	void onUpdate() override {
		OPS_PRINT_INFO("ExampleLayer::Update");
	}

	void onEvent(OPS::Event &e) override {
		OPS_PRINT_TRACE("{0}", e);
	}
};

class Test : public OPS::Application {
public:
	Test() : OPS::Application("Test App") {
		OPS_PRINT_INFO("Test App constructed");
		pushLayer(new ExampleLayer());
		pushOverlay(new OPS::ImGuiLayer());
	}

	~Test() {
		OPS_PRINT_WARN("Test App deconstructed");
	}
};

OPS_CREATE_APPLICATION(Test);