#include "stdafx.h"
#include "Application.h"


Application::Application()
	: m_quit(false)
{
}


Application::~Application()
{
}

bool Application::initialize(const char * title, int xPos, int yPos, int width, int height, int flags)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		m_window = SDL_CreateWindow(title, xPos, yPos, width, height, flags);
		m_renderer = SDL_CreateRenderer(m_window, -1, 0);
		SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
	}
	loadContent();
	return true;
}

void Application::cleanUp()
{
	SDL_DestroyWindow(m_window);
	SDL_DestroyRenderer(m_renderer);
	SDL_Quit();
}

void Application::loop()
{
	while (!m_quit)
	{
		handleEvents();
		update();
		render();

	}
}

void Application::loadContent()
{
	TextureFilter::Instance()->createJtexture("../assets/image0.png", 0, m_renderer);
}

void Application::unloadContent()
{
}

void Application::render()
{
	SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
	SDL_RenderClear(m_renderer);

	SDL_RenderCopy(m_renderer, TextureFilter::Instance()->getTexture(0), NULL, &TextureFilter::Instance()->getTextureBounds(0));

	SDL_RenderPresent(m_renderer);
}

void Application::update()
{
}

void Application::handleEvents()
{
	while (SDL_PollEvent(&m_event) != 0)
	{
		if (m_event.type == SDL_QUIT)
		{
			m_quit = true;
		}
		else
		{
			switch (m_event.type)
			{
			case SDL_KEYDOWN:
				switch (m_event.key.keysym.sym)
				{
				case SDLK_ESCAPE:
					m_quit = true;
					break;
				case SDLK_1:
					TextureFilter::Instance()->resetPixels(0);
					break;
				case SDLK_2:
					TextureFilter::Instance()->grayscaleFilter(0);
					break;
				case SDLK_3:
					TextureFilter::Instance()->pixelateFilter(0, 10);
					break;
				case SDLK_4:
					TextureFilter::Instance()->gaussianBlur1D(0, 15);
					break;
				case SDLK_5:
					TextureFilter::Instance()->bloomFilter(0, 150, 20, 0.7f);
					break;
				case SDLK_6:
					TextureFilter::Instance()->edgeDectection(0, TextureFilter::EdgeDetect);
					break;
				case SDLK_7:
					TextureFilter::Instance()->edgeDectection(0, TextureFilter::EdgeEnhance);
					break;
				case SDLK_8:
					TextureFilter::Instance()->edgeDectection(0, TextureFilter::Emboss);
					break;
				}
			}
		}
	}
}
