#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include <vector>
#include <iostream>
#include "EventListener.h"
#include "InputHandler.h"

using namespace std;

//struct for a 3 element container
template <class T1, class T2, class T3>
struct triple
{
	T1 first; //the first element
	T2 second; //the second element
	T3 third; //the third element
};

class MessageBox : public EventListener
{
public:
	
	// Creates a Message Box
	MessageBox() {};

	// Creates a Message Box with an SDL renderer passed in, and the TTF font you want to use
	MessageBox(SDL_Renderer * renderer, TTF_Font * font);

	// Destroy MessageBox
	~MessageBox() { delete this; };

	/// <summary>
	/// Adds an event driven hint to be shown (event needed to progress)
	/// </summary>
	/// <param name="mess">the message to be shown</param>
	/// <param name="time">the amount of time to show message</param>
	/// <param name="num">the order of the hint</param>
	void AddHint(const char * mess, float time, int num);

	/// <summary>
	/// Adds an event driven hint to be shown (event needed to progress)
	/// </summary>
	/// <param name="mess">the message to be shown</param>
	/// <param name="evt">specifies the event needed to progress to next hint</param>
	/// <param name="num">the order of the hint</param>
	void AddHint(const char * mess, EventListener::Event evt, int num);

	/// <summary>
	/// Update Method
	/// Checks if an event is triggered
	/// </summary>
	/// <param name="input">Instance of InputHandler</param>
	void Update(InputHandler input);

	/// <summary>
	/// Render Method
	/// </summary>
	void Render();


	void onEvent(EventListener::Event) {};

private:
	SDL_Renderer * m_renderer;
	SDL_Surface * m_surface;
	SDL_Rect m_textLoc;
	TTF_Font * m_font;
	SDL_Texture * m_texture;

	vector<SDL_Texture*> m_eventMessages; //holds all the messages
	vector<SDL_Texture*> m_textMessages; //holds all text messages

	InputHandler m_inputHandler;

	//Text Based Hints
	vector<triple<const char *, float, int>> m_textHints;
	int m_textIndex;
	float m_hintTimer;

	//Event Based Hints
	//holds all the hints, the event for each one, and the order of the hint
	//vector<triple<const char*, EventListener::Event, int>> m_eventHints;
	vector<pair<const char *, EventListener::Event>> m_eventHints;

	//holds the number of the current hint
	int m_hintIndex;

	//position of the messages to be displayed
	int m_x = 10;
	int m_y = 10;
	int m_w = 300;
	int m_h = 50;


	bool test = false;
};
