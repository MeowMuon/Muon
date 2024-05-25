#include <Muon.h>

class TestLayer :public Muon::Layer
{
public:
	TestLayer(std::string name) :Layer(name) {}

	void OnEvent(Muon::Event& e) override
	{
	}

	void Tick() override
	{
	}
};

class Sandbox :public Muon::Application
{
public:
	Sandbox()
	{
		PushLayer(new TestLayer("Layer 1"));
	}

	~Sandbox()
	{
	}
};

Muon::Application* Muon::CreateApplication()
{
	return new Sandbox();
}
