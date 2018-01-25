#include <iostream>
#include "Tutorial.h"

#undef main
int main(int argc, char *args[])
{
	Tutorial* tutorial = new Tutorial();

	if (!tutorial->Init(800, 600))
	{
		std::cout << "Tutorial failed to Initialise" << std::endl;
	}

	tutorial->Update();

	tutorial->CleanUp();

	return 0;
}