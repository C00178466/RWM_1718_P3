#pragma once

class EventListener
{
public:
	enum class Event
	{
		UP,
		DOWN,
		LEFT,
		RIGHT,
		UPR,
		DOWNR,
		LEFTR,
		RIGHTR,
		JUMP
	};

	virtual void onEvent(Event) = 0;
};
