#pragma once

#include "OpticSiege/Core/Core.h"

/**
* Events are blocking. (events are handled immediately, and will app thread)
*/

namespace OPS {
	enum class EventType {
		NONE = 0,
		WINDOW_CLOSE, WINDOW_RESIZE, WINDOW_FOCUS, WINDOW_LOST_FOCUS, WINDOW_MOVED, // Window
		APP_TICK, APP_UPDATE, APP_RENDER, // App
		KEY_PRESSED, KEY_RELEASED, KEY_TYPED, // Keys
		MOUSE_BUTTON_PRESSED, MOUSE_BUTTON_RELEASED, MOUSE_MOVE, MOUSE_SCROLLED // Mouse
	};

	enum EventCategory {
		NONE = 0,
		EVENT_CATEGORY_APPLICATION  = BIT(0),
		EVENT_CATEGORY_INPUT        = BIT(1),
		EVENT_CATEGORY_KEYBOARD     = BIT(2),
		EVENT_CATEGORY_MOUSE        = BIT(3),
		EVENT_CATEGORY_MOUSE_BUTTON = BIT(4)
	};

#define EVENT_CLASS_TYPE(type) static EventType getStaticType() { return type; }\
		virtual EventType getEventType() const override { return getStaticType(); }\
		virtual const char *getName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(cat) virtual int getCategoryFlags() const override { return cat; }

	/**
	* Main Event class
	*/
	class Event {
	public:
		virtual ~Event() = default;

		bool handled = false;

		virtual EventType getEventType() const = 0;
		virtual const char *getName() const = 0;
		virtual int getCategoryFlags() const = 0;
		virtual std::string toString() const {
			return getName();
		}

		bool isInCategory(EventCategory cat) {
			return getCategoryFlags() & cat;
		}
	};

	class EventDispatcher {
	public:
		EventDispatcher(Event &event) : _event(event) {}

		template<typename T, typename F>
		bool dispatch(const F &func) {
			if (_event.getEventType() == T::getStaticType()) {
				_event.handled |= func(static_cast<T &>(_event));
				return true;
			}
			return false;
		}

	private:
		Event &_event;
	};

	inline std::ostream &operator<<(std::ostream &os, const Event &e) {
		return os << e.toString();
	}
}