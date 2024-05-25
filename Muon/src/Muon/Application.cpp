#include "mupch.h"
#include "Application.h"

#include "Muon/Input.h"

#include "glad/glad.h"

namespace Muon
{

	Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		MU_ASSERT_CORE(!s_Instance,"Application instance already exists!")
		s_Instance = this;

		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(MU_BIND_1P(Application::OnEvent, this));

		m_GuiLayer = new ImGuiLayer();
		PushOverlay(m_GuiLayer);
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		while (m_ShouldRun)
		{
			glClearColor(0.3, 0.9, 0.9, 1.0);
			glClear(GL_COLOR_BUFFER_BIT);

			//PreTick=======================
			ImGuiLayer::Begin();

			//Tick==========================
			for (Layer* layer : m_LayerStack)
			{
				layer->Tick();
			}

			//PostTick======================
			ImGuiLayer::End();

			//End===========================

			m_Window->OnUpdate();
		}
	}

	void Application::OnEvent(Event& e)
	{
		MU_LOG_CORE(LOG_INFO, "{0}", e);

		EventDispatcher d(e);
		d.Dispatch<WindowCloseEvent>(MU_BIND_1P(Application::OnWindowClose, this));
		if (e.Handled)return;

		for (auto it = m_LayerStack.end();it != m_LayerStack.begin();)
		{
			(*--it)->OnEvent(e);
			if (e.Handled)break;
		}
	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer* overlay)
	{
		m_LayerStack.PushOverlay(overlay);
		overlay->OnAttach();
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_ShouldRun = false;
		return true;
	}

}