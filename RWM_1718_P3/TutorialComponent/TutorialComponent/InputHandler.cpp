#include "InputHandler.h"

void InputHandler::AddListener(EventListener::Event evt, EventListener *listener)
{
	if (EventListeners.find(evt) == EventListeners.end())
	{
		//event not in map add it.
		EventListeners[evt] = new std::vector<EventListener*>();
	}
	EventListeners[evt]->push_back(listener);
}

//Send the events to interested objects
void InputHandler::Dispatch(EventListener::Event evt)
{
	if (EventListeners.find(evt) != EventListeners.end())
	{
		for (auto const &listener : *EventListeners[evt])
		{ //go through all listeners for this event
			listener->onEvent(evt); //Call on event for the listener
		}
	}
}

EventListener::Event InputHandler::CheckEvent()
{
	if (m_left)
	{
		return EventListener::Event::LEFT;
	}

	if (m_right)
	{
		return EventListener::Event::RIGHT;
	}

	if (m_up)
	{
		return EventListener::Event::UP;
	}

	if (m_down)
	{
		return EventListener::Event::DOWN;
	}

	if (m_jump)
	{
		return EventListener::Event::JUMP;
	}
}

void InputHandler::CheckInput(bool & running)
{
	SDL_Event* e = new SDL_Event;
	while (SDL_PollEvent(e))
	{
		switch (e->type)
		{
		case SDL_QUIT:
			running = false;
			break;

		case SDL_KEYDOWN:
		{
			switch (e->key.keysym.sym)
			{
			case SDLK_a:
				Dispatch(EventListener::Event::LEFT);
				m_left = true;
				break;
			case SDLK_LEFT:
				Dispatch(EventListener::Event::LEFT);
				m_left = true;
				break;
			case SDLK_UP:
				Dispatch(EventListener::Event::UP);
				m_up = true;
				break;
			case SDLK_w:
				Dispatch(EventListener::Event::UP);
				m_up = true;
				break;
			case SDLK_RIGHT:
				Dispatch(EventListener::Event::RIGHT);
				m_right = true;
				break;
			case SDLK_d:
				Dispatch(EventListener::Event::RIGHT);
				m_right = true;
				break;
			case SDLK_s:
				Dispatch(EventListener::Event::DOWN);
				m_down = true;
				break;
			case SDLK_DOWN:
				Dispatch(EventListener::Event::DOWN);
				m_down = true;
				break;
			case SDLK_SPACE:
				Dispatch(EventListener::Event::JUMP);
				m_jump = true;
				break;
			default:
				break;
			}
			break;
		}

		case SDL_KEYUP:
		{
			switch (e->key.keysym.sym)
			{
			case SDLK_a:
				Dispatch(EventListener::Event::LEFTR);
				m_left = false;
				break;
			case SDLK_LEFT:
				Dispatch(EventListener::Event::LEFTR);
				m_left = false;
				break;
			case SDLK_UP:
				Dispatch(EventListener::Event::UPR);
				m_up = false;
				break;
			case SDLK_w:
				Dispatch(EventListener::Event::UPR);
				m_up = false;
				break;
			case SDLK_RIGHT:
				Dispatch(EventListener::Event::RIGHTR);
				m_right = false;
				break;
			case SDLK_d:
				Dispatch(EventListener::Event::RIGHTR);
				m_right = false;
				break;
			case SDLK_s:
				Dispatch(EventListener::Event::DOWNR);
				m_down = false;
				break;
			case SDLK_DOWN:
				Dispatch(EventListener::Event::DOWNR);
				m_down = false;
				break;
			}
			break;
		}
		}
	}
}