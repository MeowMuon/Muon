#pragma once

#include "Core.h"

namespace Muon
{

	class MUON_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();

}