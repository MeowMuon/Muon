#pragma once

#ifdef MU_PLATFORM_WINDOWS

extern Muon::Application* Muon::CreateApplication();

int main(int argc, char** argv)
{
	Muon::Log::Init();
	MU_LOG_CORE_INFO("Logging initialized.");
	MU_LOG_TRACE("Logging initialized.");

	auto app = Muon::CreateApplication();
	app->Run();
	delete app;
}

#endif