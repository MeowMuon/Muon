#pragma once

#include "Event.h"

#include <sstream>

namespace Muon
{

	class MUON_API MouseMoveEvent :public Event
	{
	public:
		EVENT_CLASS_TYPE(MouseMove);
		EVENT_CLASS_CATEGORY(EventCategory::Input | EventCategory::Mouse);

		MouseMoveEvent(float x, float y)
			:m_MouseX{ x }, m_MouseY{ y } {}

		inline float GetX() const { return m_MouseX; }
		inline float GetY() const { return m_MouseY; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMoveEvent: (" << m_MouseX << ", " << m_MouseY << ")";
			return ss.str();
		}

	protected:
		float m_MouseX;
		float m_MouseY;
	};

	class MUON_API MouseScrollEvent :public Event
	{
	public:
		EVENT_CLASS_TYPE(MouseScroll);
		EVENT_CLASS_CATEGORY(EventCategory::Input | EventCategory::Mouse);

		MouseScrollEvent(float offsetX, float offsetY)
			:m_OffsetX{ offsetX }, m_OffsetY{ offsetY } {}

		inline float GetOffsetX() const { return m_OffsetX; }
		inline float GetOffsetY() const { return m_OffsetY; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseScrollEvent: (" << m_OffsetX << ", " << m_OffsetY << ")";
			return ss.str();
		}

	protected:
		float m_OffsetX;
		float m_OffsetY;
	};

	class MUON_API MouseButtonEvent :public Event
	{
	public:
		EVENT_CLASS_CATEGORY(EventCategory::Input | EventCategory::Mouse | EventCategory::MouseButton);

		inline int GetButton() const { return m_Button; }

	protected:
		MouseButtonEvent(int button)
			:m_Button{ button } {}

		int m_Button;
	};

	class MUON_API MousePressEvent :public MouseButtonEvent
	{
	public:
		EVENT_CLASS_TYPE(MousePress)

		MousePressEvent(int button)
			:MouseButtonEvent(button) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MousePressEvent: " << m_Button;
			return ss.str();
		}
	};

	class MUON_API MouseReleaseEvent :public MouseButtonEvent
	{
	public:
		EVENT_CLASS_TYPE(MouseRelease);

		MouseReleaseEvent(int button)
			:MouseButtonEvent(button) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseReleaseEvent: " << m_Button;
			return ss.str();
		}
	};

}