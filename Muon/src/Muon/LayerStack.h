#pragma once

#include "Muon/Core/Core.h"
#include "Muon/Layer.h"

#include <vector>

namespace Muon
{

	class MUON_API LayerStack
	{
	public:
		LayerStack();
		~LayerStack();

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
		void PopLayer(Layer* layer);
		void PopOverlay(Layer* overlay);

		std::vector<Layer*>::iterator begin() { return m_Stack.begin(); }
		std::vector<Layer*>::iterator end() { return m_Stack.end(); }

	private:
		std::vector<Layer*> m_Stack;
		unsigned int m_LayersEnd;
		//std::vector<Layer*>::iterator m_LayersEnd;
	};

}
