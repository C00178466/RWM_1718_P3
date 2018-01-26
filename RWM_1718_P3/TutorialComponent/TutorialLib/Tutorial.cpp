#include "Tutorial.h"

Tutorial::Tutorial()
{
	gameRunning = true;
}

Tutorial::~Tutorial() {}

bool Tutorial::Init(int width, int height)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		return false;
	}

	IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);
	TTF_Init();

	m_window = SDL_CreateWindow("Tutorial", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
	SDL_SetRenderDrawBlendMode(m_renderer, SDL_BLENDMODE_BLEND);

	m_font = TTF_OpenFont("OpenSans.ttf", 14);
	
	m_input = InputHandler();

	m_input.AddListener(EventListener::Event::DOWN, this);
	m_input.AddListener(EventListener::Event::DOWNR, this);
	m_input.AddListener(EventListener::Event::UP, this);
	m_input.AddListener(EventListener::Event::UPR, this);
	m_input.AddListener(EventListener::Event::LEFT, this);
	m_input.AddListener(EventListener::Event::LEFTR, this);
	m_input.AddListener(EventListener::Event::RIGHT, this);
	m_input.AddListener(EventListener::Event::RIGHTR, this);
	m_input.AddListener(EventListener::Event::JUMP, this);

	messageBox = new MessageBox(m_renderer, m_font);
	messageBox->AddHint("This is the tutorial level for you here now", 5);
	messageBox->AddHint("Learn how to use the controls here", 5);
	messageBox->AddHint("Use D or RIGHT to move right", EventListener::Event::RIGHT);
	messageBox->AddHint("Use A or LEFT to move left", EventListener::Event::LEFT);
	messageBox->AddHint("Use S or Down to move down", EventListener::Event::DOWN);
	messageBox->AddHint("Use SPACE to Jump", EventListener::Event::JUMP);

	return true;
}

void Tutorial::Update()
{
	while (gameRunning == true)
	{
		m_input.CheckInput(gameRunning);
		messageBox->Update(m_input);

		Render();
	}
}

void Tutorial::Render()
{
	SDL_SetRenderDrawColor(m_renderer, 255, 0, 0, 0);
	SDL_RenderClear(m_renderer);

	//draw here
	messageBox->Render();

	SDL_RenderPresent(m_renderer);
}

void Tutorial::onEvent(EventListener::Event evt)
{
	
}

void Tutorial::CleanUp()
{
	m_window = nullptr;
	m_renderer = nullptr;
	SDL_DestroyWindow(m_window);
	SDL_DestroyRenderer(m_renderer);

	IMG_Quit();
	SDL_Quit();
}