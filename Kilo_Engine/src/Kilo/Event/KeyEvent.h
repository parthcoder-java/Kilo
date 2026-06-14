#pragma once
#include"Event.h"

namespace Kilo {
	class KeyEvent : public Event
	{
	public:
		inline int GetKey() const { return m_KeyCode; }
		EVENT_CLASS_CATAGORY(EventCatagoryInput | EventCatagoryKeyboard)

	protected:
		KeyEvent(int keycode) : m_KeyCode(keycode) {}
		int m_KeyCode;
	};

	class KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int keycode, int repeatcount) : KeyEvent(keycode), m_RepeatCount(repeatcount) {}
		inline int GetRepeatCount() { return m_RepeatCount; }

		EVENT_CLASS_TYPE(KeyPressed)

	private:
		int m_RepeatCount;
	};

	class KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int keycode) : KeyEvent(keycode) {}

		EVENT_CLASS_TYPE(KeyReleased)
	};
}