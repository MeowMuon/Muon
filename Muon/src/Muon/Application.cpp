#include "mupch.h"
#include "Application.h"

#include "Muon/Events/Event.h"
#include "Muon/Events/ApplicationEvent.h"
#include "Muon/Log.h"

namespace Muon
{

	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		MU_LOG(LOG_WARN, e.ToString());

		while (true);
	}

}