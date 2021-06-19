#pragma once

#include "OpticSiege/Core/Window/Window.h"

#include "OpticSiege/Core/ErrorHandles/GLHandles.h"

struct GLFWwindow;

namespace OPS {
	class WinPlat_Window : public Window {
	public:
		WinPlat_Window(const WindowConfig &config);
		virtual ~WinPlat_Window();

		void onUpdate() override;

		inline unsigned int getWidth() const override {
			return _data.width;
		}

		inline unsigned int getHeight() const override {
			return _data.height;
		}

		inline void setEventCallBack(const EventCallBack &callback) override {
			_data.eventCallBack = callback;
		}

		void setVSync(bool enables);
		bool isVSync() const;

		virtual void *getNativeWindow() const {
			return _window;
		}

	private:
		GLFWwindow *_window;

		virtual void init(const WindowConfig &config);
		virtual void shutdown();

		struct WindowData {
			std::string title;
			unsigned int width, height;
			bool vSync;

			EventCallBack eventCallBack;
		};

		WindowData _data;
	};
}