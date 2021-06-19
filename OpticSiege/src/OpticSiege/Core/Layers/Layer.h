#pragma once

#include "OpticSiege/Core/Core.h"
#include "OpticSiege/Core/Events/Event.h"

namespace OPS {
	class Layer {
	public:
		Layer(const std::string &name = "Layer");
		virtual ~Layer();

		virtual void onAttach() {}
		virtual void onDetach() {}
		virtual void onUpdate() {}
		virtual void onImGuiRender() {}
		virtual void onEvent(Event &event) {}

		inline const std::string &getName() const {
			return _debugName;
		}
	protected:
		std::string _debugName;
	};
}