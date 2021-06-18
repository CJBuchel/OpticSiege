#pragma once

#include "ops_pch.h"
#include "OpticSiege/Events/Event.h"

namespace OPS {
	class WindowResizeEvent : public Event {
	public:
		WindowResizeEvent(unsigned int width, unsigned int height) : _width(width), _height(height) {
		}

		unsigned int getWidth() const {
			return _width;
		}

		unsigned int getHeight() const {
			return _height;
		}

		std::string toString() const override {
			std::stringstream ss;
			ss << "Window Resize Event: " << _width << ", " << _height;
			return ss.str();
		}

		EVENT_CLASS_TYPE(EventType::WINDOW_RESIZE);
		EVENT_CLASS_CATEGORY(EventCategory::EVENT_CATEGORY_APPLICATION);
	private:
		unsigned int _width, _height;
	};

	class WindowCloseEvent : public Event {
	public:
		WindowCloseEvent() = default;

		EVENT_CLASS_TYPE(EventType::WINDOW_CLOSE);
		EVENT_CLASS_CATEGORY(EventCategory::EVENT_CATEGORY_APPLICATION);
	};

	class AppTickEvent : public Event {
	public:
		AppTickEvent() = default;

		EVENT_CLASS_TYPE(EventType::APP_TICK);
		EVENT_CLASS_CATEGORY(EventCategory::EVENT_CATEGORY_APPLICATION);
	};

	class AppUpdateEvent : public Event {
	public:
		AppUpdateEvent() = default;

		EVENT_CLASS_TYPE(EventType::APP_UPDATE);
		EVENT_CLASS_CATEGORY(EventCategory::EVENT_CATEGORY_APPLICATION);
	};

	class AppRenderEvent : public Event {
	public:
		AppRenderEvent() = default;

		EVENT_CLASS_TYPE(EventType::APP_RENDER);
		EVENT_CLASS_CATEGORY(EventCategory::EVENT_CATEGORY_APPLICATION);
	};
}