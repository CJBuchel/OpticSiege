#pragma once

#include "OpticSiege/Core/Core.h"
#include "OpticSiege/Core/Events/Event.h"

namespace OPS {
	struct WindowConfig {
		std::string title;
		unsigned int width, height;

		WindowConfig(const std::string &title = "OpticSiege Window", unsigned int width = 1280, unsigned int height = 720)
			: title(title), width(width), height(height) {

		}
	};

	class Window {
	public:
		using EventCallBack = std::function<void(Event&)>;

		virtual ~Window() {}

		virtual void onUpdate() = 0;

		/**
		* General config
		*/
		virtual unsigned int getWidth() const = 0;
		virtual unsigned int getHeight() const = 0;

		/**
		* main Setters/Getters
		*/
		virtual void setEventCallBack(const EventCallBack &callback) = 0;
		virtual void setVSync(bool enable) = 0;
		virtual bool isVSync() const = 0;

		virtual void *getNativeWindow() const = 0;

		static Window *create(const WindowConfig &config = WindowConfig());
	};
}