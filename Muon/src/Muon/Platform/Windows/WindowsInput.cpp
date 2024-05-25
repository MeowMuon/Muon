#include "mupch.h"
#include "WindowsInput.h"

#include "GLFW/glfw3.h"
#include "Muon/Application.h"

namespace Muon
{

	Input* Input::s_Instance = new WindowsInput();

	bool WindowsInput::IsKeyPressed_I(int keycode)
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		auto state = glfwGetKey(window, keycode);
		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}

	bool WindowsInput::IsMousePressed_I(int button)
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		auto state = glfwGetMouseButton(window, button);
		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}

	float WindowsInput::GetMouseX_I()
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		double x, y;
		glfwGetCursorPos(window, &x, &y);
		return (float)x;
	}

	float WindowsInput::GetMouseY_I()
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		double x, y;
		glfwGetCursorPos(window, &x, &y);
		return (float)y;
	}

}