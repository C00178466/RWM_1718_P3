#include "MessageBox.h"

MessageBox::MessageBox(SDL_Renderer * renderer, TTF_Font * font) :
	m_renderer(renderer), m_font(font)
{
	m_textLoc.x = m_x;
	m_textLoc.y = m_y;
	m_textLoc.w = m_w;
	m_textLoc.h = m_h;

	m_hintIndex = 0;
	m_textIndex = 0;
	m_hintTimer = 0;
}

void MessageBox::AddHint(const char * mess, float time)
{
	pair<const char*, float> temp;
	temp.first = mess;
	temp.second = time;

	m_surface = TTF_RenderText_Blended_Wrapped(m_font, temp.first, { 0, 0, 0 }, 200);
	m_texture = SDL_CreateTextureFromSurface(m_renderer, m_surface);
	SDL_FreeSurface(m_surface);
	m_textMessages.push_back(m_texture);

	m_textHints.push_back(temp);
}

void MessageBox::AddHint(const char * mess, EventListener::Event evt)
{
	//add event to the list if its not there already
	m_inputHandler.AddListener(evt, this);

	pair<const char*, EventListener::Event> temp;
	temp.first = mess;
	temp.second = evt;

	m_surface = TTF_RenderText_Blended_Wrapped(m_font, temp.first, { 0, 0, 0 }, 200);
	m_texture = SDL_CreateTextureFromSurface(m_renderer, m_surface);
	SDL_FreeSurface(m_surface);
	m_eventMessages.push_back(m_texture);

	m_eventHints.push_back(temp);
}

void MessageBox::Update(InputHandler input)
{
	//check all elements in the text only hints
	//then continue to the event driven hints
	//go from the last element and cycle backwards

	if (m_textIndex < m_textHints.size()) //while there is something in the text-driven hints vector
	{
		m_hintTimer += 1.0f / 60.0f;

		//timer for each hint
		if (m_hintTimer > m_textHints.at(m_textIndex).second)
		{
			if (m_textIndex < m_textHints.size() - 1)
			{
				m_textIndex++;
			}
			else
			{
				m_textHintOver = true;
			}
			
			m_hintTimer = 0.0f;
		}
	}

	if (m_textHintOver)
	{
		if (m_hintIndex < m_eventHints.size())
		{
			if (input.CheckEvent() == m_eventHints.at(m_hintIndex).second) //check if event pressed matches the event given in the hint
			{
				if (m_hintIndex < m_eventHints.size() - 1)
				{
					m_hintIndex++;
					cout << "Event Pressed" << endl;
				}
			}
		}
	}
}

void MessageBox::Render()
{
	//check all elements in the text only hints
	//then continue to the event driven hints
	
	if (m_textHintOver)
	{
		if (m_hintIndex <= m_eventHints.size())
		{
			SDL_RenderCopy(m_renderer, m_eventMessages.at(m_hintIndex), NULL, &m_textLoc);
		}
	}

	else if (m_textIndex <= m_textHints.size())
	{
		SDL_RenderCopy(m_renderer, m_textMessages.at(m_textIndex), NULL, &m_textLoc);
	}
}