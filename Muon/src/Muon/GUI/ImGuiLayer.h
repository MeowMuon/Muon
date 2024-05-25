#pragma once

#include "Muon/Layer.h"

#include "Muon/Events/ApplicationEvent.h"
#include "Muon/Events/KeyEvent.h"
#include "Muon/Events/MouseEvent.h"

namespace Muon
{

	class MUON_API ImGuiLayer :public Layer
	{
	public:
		ImGuiLayer(const std::string& name = "GUI");
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;

		virtual void Tick() override;

		static void Begin();
		static void End();
	};

}
