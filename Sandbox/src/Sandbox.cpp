#include <Muon.h>

class TestLayer :public Muon::Layer
{
public:
	TestLayer(std::string name) :Layer(name) {}

	void OnEvent(Muon::Event& e) override
	{
	}

	void OnUpdate() override
	{
	}
};

class Sandbox :public Muon::Application
{
public:
	Sandbox()
	{
		PushLayer(new TestLayer("Layer 1"));
		PushOverlay(new Muon::ImGuiLayer());
	}

	~Sandbox()
	{
	}
};

Muon::Application* Muon::CreateApplication()
{
	return new Sandbox();
}