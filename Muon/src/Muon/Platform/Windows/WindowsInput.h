#pragma once

#include "Muon/Input.h"

namespace Muon
{

	class WindowsInput :public Input
	{
	protected:
		virtual bool IsKeyPressed_I(int keycode) override;
		virtual bool IsMousePressed_I(int button);
		virtual float GetMouseX_I();
		virtual float GetMouseY_I();
	};

}
