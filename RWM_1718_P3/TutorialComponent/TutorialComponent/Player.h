#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "EventListener.h"
#include <iostream>

using namespace std;

class Player : public EventListener
{
public:
	Player() {};
	Player(SDL_Renderer * renderer);
	~Player() {};

	void Update();
	void Render(SDL_Renderer * renderer);
	void onEvent(EventListener::Event evt);

	//Movement
	void MoveRight();
	void MoveLeft();
	void MoveDown();
	void MoveUp();

private:
	SDL_Texture * m_texture;
	SDL_Rect m_frameRect;
	SDL_Rect m_rect;

	//Movement
	bool m_left;
	bool m_right;
	bool m_up;
	bool m_down;
};