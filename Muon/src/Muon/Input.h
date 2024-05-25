#pragma once

#include "Muon/Core/Core.h"

namespace Muon
{

	class MUON_API Input
	{
	public:
		static bool IsKeyPressed(int keycode) { return s_Instance->IsKeyPressed_I(keycode); }
		static bool IsMousePressed(int button) { return s_Instance->IsMousePressed_I(button); }
		static float GetMouseX() { return s_Instance->GetMouseX_I(); }
		static float GetMouseY() { return s_Instance->GetMouseY_I(); }

	protected:
		virtual bool IsKeyPressed_I(int keycode) = 0;
		virtual bool IsMousePressed_I(int button) = 0;
		virtual float GetMouseX_I() = 0;
		virtual float GetMouseY_I() = 0;

	private:
		static Input* s_Instance;
	};

}