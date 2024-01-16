#include "mupch.h"
#include "Application.h"

#include "Muon/Events/Event.h"
#include "Muon/Events/ApplicationEvent.h"

namespace Muon
{

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		while (m_ShouldRun)
		{
			m_Window->OnUpdate();
		}
	}

}