// ConsoleApplication1.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#pragma once
#define SDL_MAIN_HANDLED
#ifdef _DEBUG 
#pragma comment(lib, "SDL_Texture_Filter-D.lib")
#else 
#pragma comment(lib,"SDL_Texture_Filter.lib") 
#endif 

#include "Application.h"

int main(int argc, char* args[])
{
	Application* app = new Application();

	app->initialize("Simple Implementation Texture Filter", 500, 200, 800, 600, SDL_WINDOW_INPUT_FOCUS);
	app->loop();
	app->cleanUp();
	system("Pause");
	return 0;
}