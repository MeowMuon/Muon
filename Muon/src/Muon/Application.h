#pragma once

#include "Core.h"
#include "Window.h"

#include "Muon/Events/Event.h"
#include "Muon/Events/ApplicationEvent.h"

#include "Muon/LayerStack.h"

namespace Muon
{

	class MUON_API Application
	{
	public:
		Application();
		virtual ~Application();
		inline static Application& Get() { return *s_Instance; }

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		inline Window& GetWindow() { return *m_Window; }

	private:
		static Application* s_Instance;

		bool OnWindowClose(WindowCloseEvent& e);

		bool m_ShouldRun = true;
		std::unique_ptr<Window> m_Window;
		LayerStack m_LayerStack;
	};

	Application* CreateApplication();

}