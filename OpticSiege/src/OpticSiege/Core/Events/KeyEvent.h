#pragma once

#include "OpticSiege/Core/Events/Event.h"
#include "OpticSiege/Core/Codes/KeyCodes.h"

namespace OPS {
	class KeyEvent : public Event {
	public:
		KeyCode getKeyCode() const {
			return _keycode;
		}

		EVENT_CLASS_CATEGORY(EventCategory::EVENT_CATEGORY_KEYBOARD | EventCategory::EVENT_CATEGORY_INPUT);

	protected:
		KeyEvent(const KeyCode keycode) : _keycode(keycode) {
		}

		KeyCode _keycode;
	};

	class KeyPressedEvent : public KeyEvent {
	public:
		KeyPressedEvent(const KeyCode keycode, const uint16_t repeatCount) : KeyEvent(keycode), _repeatCount(repeatCount) {}

		uint16_t getRepeatCount() const {
			return _repeatCount;
		}

		std::string toString() const override {
			std::stringstream ss;
			ss << "KeyPressedEvent: " << _keycode << " (" << _repeatCount << " repeats)";
			return ss.str();
		}

		EVENT_CLASS_TYPE(EventType::KEY_PRESSED);
	private:
		uint16_t _repeatCount;
	};

	class KeyReleasedEvent : public KeyEvent {
	public:
		KeyReleasedEvent(const KeyCode keycode) : KeyEvent(keycode) {}

		std::string toString() const override {
			std::stringstream ss;
			ss << "Key Released Event: " << _keycode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(EventType::KEY_RELEASED);
	};

	class KeyTypedEvent : public KeyEvent {
	public:
		KeyTypedEvent(const KeyCode keycode) : KeyEvent(keycode) {}

		std::string toString() const override {
			std::stringstream ss;
			ss << "Key Typed Event: " << _keycode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(EventType::KEY_TYPED);
	};
}