#pragma once

#include "OpticSiege/Events/Event.h"
#include "OpticSiege/Codes/MouseCodes.h"

namespace OPS {
	class MouseMoveEvent : Event {
	public:
		MouseMoveEvent(const float x, const float y) : _mouseX(x), _mouseY(y) {
		}

		float getX() const {
			return _mouseX;
		}

		float getY() const {
			return _mouseY;
		}

		std::string toString() const override {
			std::stringstream ss;
			ss << "Mouse Moved Event: " << _mouseX << ", " << _mouseY;
			return ss.str();
		}

		EVENT_CLASS_TYPE(EventType::MOUSE_MOVED);
		EVENT_CLASS_CATEGORY(EventCategory::EVENT_CATEGORY_MOUSE | EventCategory::EVENT_CATEGORY_INPUT);

	private:
		float _mouseX, _mouseY;
	};

	class MouseScrolledEvent : public Event {
	public:
		MouseScrolledEvent(const float xOffset, const float yOffset) : _xOffset(xOffset), _yOffset(yOffset) {
		}

		float getXOffset() const {
			return _xOffset;
		}
		float getYOffset() const {
			return _yOffset;
		}

		std::string toString() const override {
			std::stringstream ss;
			ss << "Mouse Scrolled Event: " << getXOffset() << ", " << getYOffset();
			return ss.str();
		}

		EVENT_CLASS_TYPE(EventType::MOUSE_SCROLLED);
		EVENT_CLASS_CATEGORY(EventCategory::EVENT_CATEGORY_MOUSE | EventCategory::EVENT_CATEGORY_INPUT);
	private:
		float _xOffset, _yOffset;
	};

	class MouseButtonEvent : public Event {
	public:
		MouseCode getMouseButton() const {
			return _button;
		}

		EVENT_CLASS_CATEGORY(EventCategory::EVENT_CATEGORY_MOUSE | EventCategory::EVENT_CATEGORY_INPUT | EventCategory::EVENT_CATEGORY_MOUSE_BUTTON);
	protected:
		MouseButtonEvent(const MouseCode button) : _button(button) {
		}

		MouseCode _button;
	};

	class MouseButtonPressedEvent : public MouseButtonEvent {
	public:
		MouseButtonPressedEvent(const MouseCode button) : MouseButtonEvent(button) {
		}

		std::string toString() const override {
			std::stringstream ss;
			ss << "Mouse Button Pressed Event: " << _button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(EventType::MOUSE_BUTTON_PRESSED);
	};

	class MouseButtonReleasedEvent : public MouseButtonEvent {
	public:
		MouseButtonReleasedEvent(const MouseCode button): MouseButtonEvent(button) {
		}

		std::string toString() const override {
			std::stringstream ss;
			ss << "Mouse Button Released Event: " << _button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(EventType::MOUSE_BUTTON_RELEASED);
	};
}