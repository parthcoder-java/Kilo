#pragma once
#include"Event.h"

namespace Kilo {
	class KILO_API MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(float x, float y): m_MouseX(x), m_MouseY(y) {}

		inline float GetMouseX() const { return m_MouseX; }
		inline float GetMouseY() const { return m_MouseY; }

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATAGORY(EventCatagoryMouse | EventCatagoryInput)
	private:
		float m_MouseX, m_MouseY;
	};

	class MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(float OffsetX, float OffsetY): m_OffsetX(OffsetX), m_OffsetY(OffsetY){}

		inline float GetScrollOffsetX() const { return m_OffsetX; }
		inline float GetScrollOffsetY() const { return m_OffsetY; }

		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATAGORY(EventCatagoryMouse | EventCatagoryInput)
	private:
		float m_OffsetX, m_OffsetY;
	};

	class KILO_API MouseButtonEvent : public Event
	{
	public:
		inline int GetMouseButton() const { return m_Button; }

		EVENT_CLASS_TYPE(MouseButtonPressed)

	protected:
		MouseButtonEvent(int button)
			: m_Button(button) {
		}
		int m_Button;
	};

	class KILO_API MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int button) : MouseButtonEvent(button) {}

		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	class KILO_API MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int button) : MouseButtonEvent(button) {}

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};
}