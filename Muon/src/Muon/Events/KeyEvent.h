#pragma once

#include "Event.h"

#include <sstream>

namespace Muon
{

	class MUON_API KeyEvent :public Event
	{
	public:
		EVENT_CLASS_CATEGORY(EventCategory::EECInput | EventCategory::EECKeyboard);

		inline int GetKeyCode() const { return m_KeyCode; }

	protected:
		KeyEvent(int keyCode)
			:m_KeyCode{ keyCode } {}

		int m_KeyCode;
	};

	class MUON_API KeyPressEvent :public KeyEvent
	{
	public:
		EVENT_CLASS_TYPE(KeyPress);

		KeyPressEvent(int keyCode, int repeatCount)
			:KeyEvent(keyCode), m_RepeatCount{ repeatCount } {}

		inline int GetRepeatCount() const { return m_RepeatCount; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressEvent: " << m_KeyCode << " (" << m_RepeatCount << " repeats)";
			return ss.str();
		}

	protected:
		int m_RepeatCount;
	};

	class MUON_API KeyReleaseEvent :public KeyEvent
	{
	public:
		EVENT_CLASS_TYPE(KeyRelease);

		KeyReleaseEvent(int keyCode)
			:KeyEvent(keyCode) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleaseEvent: " << m_KeyCode;
			return ss.str();
		}
	};

	class MUON_API KeyTypeEvent :public KeyEvent
	{
	public:
		EVENT_CLASS_TYPE(KeyType);

		KeyTypeEvent(int keyCode)
			:KeyEvent(keyCode) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyTypeEvent: " << m_KeyCode;
			return ss.str();
		}
	};

}