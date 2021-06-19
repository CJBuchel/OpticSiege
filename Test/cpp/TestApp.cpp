#include "TestApp.hpp"

#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
glm::mat4 camera(float Translate, glm::vec2 const &Rotate) {
	glm::mat4 Projection = glm::perspective(glm::radians(45.0f), 4.0f / 3.0f, 0.1f, 100.f);
	glm::mat4 View = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -Translate));
	View = glm::rotate(View, Rotate.y, glm::vec3(-1.0f, 0.0f, 0.0f));
	View = glm::rotate(View, Rotate.x, glm::vec3(0.0f, 1.0f, 0.0f));
	glm::mat4 Model = glm::scale(glm::mat4(1.0f), glm::vec3(0.5f));
	return Projection * View * Model;
}

class ExampleLayer : public OPS::Layer {
public:
	ExampleLayer() : Layer("Example Layer") {
		OPS_PRINT_INFO("Example layer created");
		auto cam = camera(5.0f, { 0.5f, 0.5f });
	}

	void onUpdate() override {
		OPS_PRINT_INFO("ExampleLayer::Update");
	}

	void onEvent(OPS::Event &e) override {
		if (e.getEventType() == OPS::EventType::KEY_PRESSED) {
			OPS::KeyPressedEvent &e_key = (OPS::KeyPressedEvent &)e;
			OPS_PRINT_TRACE("{0}", (char)e_key.getKeyCode());
		}
	}
};

class Test : public OPS::Application {
public:
	Test() : OPS::Application("Test App") {
		OPS_PRINT_INFO("Test App constructed");
		pushLayer(new ExampleLayer());
	}

	~Test() {
		OPS_PRINT_WARN("Test App deconstructed");
	}
};

OPS_CREATE_APPLICATION(Test);