#include "Player.h"

Player::Player(SDL_Renderer * renderer)
{
	m_texture = IMG_LoadTexture(renderer, "stickman.png");

	m_frameRect.x = m_frameRect.y = 0;
	m_frameRect.w = 1200;
	m_frameRect.h = 1694;

	m_rect.x = m_rect.y = 100;
	m_rect.w = 64;
	m_rect.h = 64;
}

void Player::Update()
{
	if (m_left)
	{
		MoveLeft();
	}

	else if (m_right)
	{
		MoveRight();
	}

	else if (m_up)
	{
		MoveUp();
	}

	else if (m_down)
	{
		MoveDown();
	}
}

void Player::Render(SDL_Renderer * renderer)
{
	SDL_RenderCopy(renderer, m_texture, &m_frameRect, &m_rect);
}

void Player::onEvent(EventListener::Event evt)
{
	if (evt == EventListener::Event::DOWN)
	{
		m_down = true;
	}

	if (evt == EventListener::Event::UP)
	{
		m_up = true;
	}

	if (evt == EventListener::Event::LEFT)
	{
		m_left = true;
	}

	if (evt == EventListener::Event::RIGHT)
	{
		m_right = true;
	}

	if (evt == EventListener::Event::DOWNR)
	{
		m_down = false;
	}

	if (evt == EventListener::Event::UPR)
	{
		m_up = false;
	}

	if (evt == EventListener::Event::LEFTR)
	{
		m_left = false;
	}

	if (evt == EventListener::Event::RIGHTR)
	{
		m_right = false;
	}
}

void Player::MoveLeft()
{
	cout << "Left Pressed" << endl;

	m_rect.x -= 5;
}

void Player::MoveRight()
{
	cout << "Right Pressed" << endl;

	m_rect.x += 5;
}

void Player::MoveUp()
{
	cout << "Up Pressed" << endl;

	m_rect.y -= 5;
}

void Player::MoveDown()
{
	cout << "Down Pressed" << endl;

	m_rect.y += 5;
}