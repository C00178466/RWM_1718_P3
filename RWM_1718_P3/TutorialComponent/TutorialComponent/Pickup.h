#pragma once
#include "SDL.h"
#include "SDL_image.h"

class Pickup
{
public:
	Pickup() {};
	Pickup(int x, int y, SDL_Renderer * renderer);
	~Pickup() {};

	void Update();
	void Render(SDL_Renderer * renderer);

private:
	SDL_Texture * m_texture;
	SDL_Rect m_frameRect;
	SDL_Rect m_rect;
};