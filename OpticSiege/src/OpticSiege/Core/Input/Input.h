#pragma once

#include "OpticSiege/Core/Core.h"

namespace OPS {
	class Input {
	public:
		inline static bool isKeyPressed(int keycode) {
			return _instance->isKeyPressedImpl(keycode);
		}

		inline static bool isMouseButtonPressed(int button) {
			return _instance->isMouseButtonPressedImpl(button);
		}

		inline static float getMouseX() {
			return _instance->getMouseXImpl();
		}

		inline static float getMouseY() {
			return _instance->getMouseYImpl();
		}

		inline static std::pair<float, float> getMousePos() {
			return _instance->getMousePosImpl();
		}

	protected:
		virtual bool isKeyPressedImpl(int keycode) = 0;
		virtual bool isMouseButtonPressedImpl(int button) = 0;
		virtual float getMouseXImpl() = 0;
		virtual float getMouseYImpl() = 0;
		virtual std::pair<float, float> getMousePosImpl() = 0;

	private:
		static Input *_instance;
	};
}