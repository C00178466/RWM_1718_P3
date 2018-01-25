#include "Pickup.h"

Pickup::Pickup(int x, int y, SDL_Renderer * renderer)
{
	m_texture = IMG_LoadTexture(renderer, "bitcoin.jpg");

	m_frameRect.x = m_frameRect.y = 0;
	m_frameRect.w = 225;
	m_frameRect.h = 224;

	m_rect.x = x;
	m_rect.y = y;
	m_rect.w = 32;
	m_rect.h = 32;
}

void Pickup::Update()
{

}

void Pickup::Render(SDL_Renderer * renderer)
{
	SDL_RenderCopy(renderer, m_texture, &m_frameRect, &m_rect);
}