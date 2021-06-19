#pragma once

#include "OpticSiege/Core/Input/Input.h"

namespace OPS {
	class WinPlat_Input : public Input {
	protected:
		virtual bool isKeyPressedImpl(int keycode) override;
		virtual bool isMouseButtonPressedImpl(int button) override;
		virtual std::pair<float, float> getMousePosImpl() override;
		virtual float getMouseXImpl() override;
		virtual float getMouseYImpl() override;
	};
}