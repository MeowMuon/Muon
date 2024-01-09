#include <Muon.h>

class Sandbox :public Muon::Application
{
public:
	Sandbox() {};
	~Sandbox() {};
};

Muon::Application* Muon::CreateApplication()
{
	return new Sandbox();
}