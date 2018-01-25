#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "InputHandler.h"
#include "Player.h"
#include "Pickup.h"
#include "MessageBox.h"
#include <vector>

using namespace std;

class Tutorial : public EventListener
{
public:
	Tutorial();
	~Tutorial();

	bool Init(int width, int height);
	void Update();
	void Render();
	void CleanUp();
	void onEvent(EventListener::Event);

private:
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
	SDL_Event m_e;
	TTF_Font * m_font;

	bool gameRunning;

	EventListener * m_evtLis;
	InputHandler m_input;

	Player * player;
	Pickup * coin;
	MessageBox * messageBox;
};