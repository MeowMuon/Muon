#pragma once

#include "Core.h"
#include "Window.h"

#include "Muon/Events/Event.h"
#include "Muon/Events/ApplicationEvent.h"

namespace Muon
{

	class MUON_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

	private:
		bool m_ShouldRun = true;
		std::unique_ptr<Window> m_Window;

		bool OnWindowClose(WindowCloseEvent& e);
	};

	Application* CreateApplication();

}