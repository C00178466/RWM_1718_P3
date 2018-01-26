#pragma once
#include "SDL.h"
#include "EventListener.h"
#include <vector>
#include <map>

using namespace std;

class InputHandler
{
public:
	InputHandler() {};
	~InputHandler() {};

	void AddListener(EventListener::Event, EventListener *);
	void Dispatch(EventListener::Event);
	void CheckInput(bool & running);

	//method that returns an Event
	EventListener::Event CheckEvent();

private:
	map<EventListener::Event, vector<EventListener*>*> EventListeners;
	bool m_left = false;
	bool m_right = false;
	bool m_up = false;
	bool m_down = false;
	bool m_jump = false;
};