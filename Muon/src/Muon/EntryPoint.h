#pragma once

#ifdef MU_PLATFORM_WINDOWS

extern Muon::Application* Muon::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Muon::CreateApplication();
	app->Run();
	delete app;
}

#endif