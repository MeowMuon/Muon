#pragma once

#include "Event.h"

#include <sstream>

namespace Muon
{

	class MUON_API WindowCloseEvent :public Event
	{
	public:
		EVENT_CLASS_TYPE(WindowClose);
		EVENT_CLASS_CATEGORY(EventCategory::Application);

		WindowCloseEvent() {}
	};

	class MUON_API WindowResizeEvent :public Event
	{
	public:
		EVENT_CLASS_TYPE(WindowResize);
		EVENT_CLASS_CATEGORY(EventCategory::Application);

		WindowResizeEvent(float width, float height)
			:m_Width{ width }, m_Height{ height } {}

		inline float GetWidth() const { return m_Width; }
		inline float GetHeight() const { return m_Height; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowResizeEvent: (" << m_Width << ", " << m_Height << ")";
			return ss.str();
		}

	protected:
		float m_Width;
		float m_Height;
	};

	class MUON_API AppTickEvent :public Event
	{
	public:
		EVENT_CLASS_TYPE(AppTick);
		EVENT_CLASS_CATEGORY(EventCategory::Application);

		AppTickEvent() {}
	};

	class MUON_API AppUpdateEvent :public Event
	{
	public:
		EVENT_CLASS_TYPE(AppUpdate);
		EVENT_CLASS_CATEGORY(EventCategory::Application);

		AppUpdateEvent() {}
	};

	class MUON_API AppRenderEvent :public Event
	{
	public:
		EVENT_CLASS_TYPE(AppRender);
		EVENT_CLASS_CATEGORY(EventCategory::Application);

		AppRenderEvent() {}
	};

}