#pragma once

#include "Core.h"
#include "Window.h"

namespace Muon
{

	class MUON_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

	private:
		bool m_ShouldRun = true;
		std::unique_ptr<Window> m_Window;
	};

	Application* CreateApplication();

}