#pragma once
#include "OpticSiege/Core/Layers/Layer.h"

namespace OPS {
	class ImGuiLayer : public Layer {
	public:
		ImGuiLayer();
		~ImGuiLayer();

		//virtual void onUpdate() override; // temp
		virtual void onAttach() override;
		virtual void onDetach() override;
		virtual void onEvent(Event &e) override;

		void begin();
		void end();

		void blockEvent(bool block) {
			_blockEvents = block;
		}

		void setDarkThemeColours();

	private:
		bool _blockEvents = true;
		float _time = 0.0f;
	};
}
