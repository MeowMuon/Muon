#include "mupch.h"
#include "Application.h"

namespace Muon
{

#define MU_BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(MU_BIND_EVENT_FN(OnEvent));
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

	void Application::OnEvent(Event& e)
	{
		MU_LOG_CORE_TEMP("{0}", e.ToString());

		EventDispatcher d(e);
		d.Dispatch<WindowCloseEvent>(MU_BIND_EVENT_FN(OnWindowClose));
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_ShouldRun = false;
		return true;
	}

}