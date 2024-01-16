#pragma once
#include "Muon/Window.h"

#include "GLFW/glfw3.h"

namespace Muon
{

	class WindowsWindow :public Window
	{
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void OnUpdate() override;

		inline unsigned int GetWidth() const override { return m_Data.Width; };
		inline unsigned int GetHeight() const override { return m_Data.Height; };

		inline void SetEventCallback(const EventCallbackFn& callback) override { m_Data.Callback = callback; }
		void SetVSync(bool enabled) override;
		bool IsVSync() const override { return m_Data.VSync; }

	private:
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();

	private:
		struct WindowData
		{
			std::string Title;
			unsigned int Width;
			unsigned int Height;
			bool VSync;

			EventCallbackFn Callback;
		};

		GLFWwindow* m_Window;
		WindowData m_Data;
	};

}