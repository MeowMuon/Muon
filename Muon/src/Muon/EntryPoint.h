#pragma once

#ifdef MU_PLATFORM_WINDOWS

extern Muon::Application* Muon::CreateApplication();

int main(int argc, char** argv)
{
	Muon::Log::Init();
	MU_LOG_CORE(LOG_INFO, "Logging initialized.");
	MU_LOG(LOG_INFO, "Logging initialized.");

	auto app = Muon::CreateApplication();
	app->Run();
	delete app;
}

#endif