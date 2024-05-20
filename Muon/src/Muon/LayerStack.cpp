#include "mupch.h"
#include "LayerStack.h"

namespace Muon
{

	LayerStack::LayerStack()
	{
		m_LayersEnd = 0;
	}

	LayerStack::~LayerStack()
	{
		for (Layer* layer : m_Stack)
		{
			delete layer;
		}
	}

	void LayerStack::PushLayer(Layer* layer)
	{
		m_Stack.emplace(m_Stack.begin()+m_LayersEnd, layer);
		m_LayersEnd++;
	}

	void LayerStack::PushOverlay(Layer* overlay)
	{
		m_Stack.emplace_back(overlay);
	}

	void LayerStack::PopLayer(Layer* layer)
	{
		auto begin = m_Stack.begin();
		std::vector<Layer*>::iterator it = std::find(begin, begin + m_LayersEnd, layer);
		if (it != m_Stack.begin() + m_LayersEnd)
		{
			m_Stack.erase(it);
			m_LayersEnd--;
		}
	}

	void LayerStack::PopOverlay(Layer* overlay)
	{
		auto begin = m_Stack.begin();
		std::vector<Layer*>::iterator it = std::find(begin + m_LayersEnd, m_Stack.end(), overlay);
		if (it != m_Stack.end())
		{
			m_Stack.erase(it);
		}
	}

}
