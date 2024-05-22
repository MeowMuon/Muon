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
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach() override;
		void OnDetach() override;
		void OnUpdate() override;
		void OnEvent(Event& e) override;

	private:
		bool OnMouseMove(MouseMoveEvent& e);
		bool OnMouseScroll(MouseScrollEvent& e);
		bool OnMouseButtonPress(MousePressEvent& e);
		bool OnMouseButtonRelease(MouseReleaseEvent& e);
		bool OnKeyType(KeyTypeEvent& e);
		bool OnKeyPress(KeyPressEvent& e);
		bool OnKeyRelease(KeyReleaseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);

		float m_Time = 0.f;
	};

}
