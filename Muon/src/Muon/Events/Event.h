#pragma once

#include "Muon/Core.h"

#include <string>
#include <functional>

namespace Muon
{

	#define EVENT_CLASS_TYPE(type) \
		static EventType GetStaticType() { return EventType::##type; }\
		virtual EventType GetType() const override { return GetStaticType(); }\
		virtual const char* GetName() const override { return #type; }

	#define EVENT_CLASS_CATEGORY(category) \
		virtual int GetCategory() const override { return category; }

	enum class EventType
	{
		None = 0,

		WindowClose,
		WindowResize,
		WindowFocus,
		WindowMove,

		AppTick,
		AppUpdate,
		AppRender,

		KeyPress,
		KeyRelease,
		KeyType,

		MousePress,
		MouseRelease,
		MouseScroll,
		MouseMove,

		MAX
	};

	enum EventCategory
	{
		EECNone = 0,
		EECApplication = BIT(0),
		EECInput = BIT(1),
		EECKeyboard = BIT(2),
		EECMouse = BIT(3),
		EECMouseButton = BIT(4),
	};

	class MUON_API Event
	{
		friend class EventDispatcher;

	public:
		virtual EventType GetType() const = 0;
		virtual int GetCategory() const = 0;
		virtual const char* GetName() const = 0;
		virtual std::string ToString() const { return GetName(); }

		inline bool IsInCategory(EventCategory category) { return GetCategory() & (int)category; }

		bool Handled = false;
	};

	class MUON_API EventDispatcher
	{
		template<typename T>
		using EventFn = std::function<bool(T&)>;

	public:
		EventDispatcher(Event& event)
			:m_Event{ event } {}

		template<typename T>
		bool Dispatch(EventFn<T> func)
		{
			if (m_Event.GetType() == T::GetStaticType())
			{
				m_Event.Handled = func(*(T*)&m_Event);
				return true;
			}
			return false;
		}

	protected:
		Event& m_Event;
	};

}