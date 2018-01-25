#include "pch.h"
#include "JTexture.h"

TEST(TestCaseName, TestName) {

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "SDL init success" << std::endl;
		SDL_Window* window = SDL_CreateWindow("Test", 0, 0, 0, 0, 0);
		SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

		JTexture* temp = new JTexture();
		if (temp->loadFromFile("../assets/image0.png", renderer))
		{
			EXPECT_TRUE(true);
		}
		else {
			EXPECT_TRUE(false);
		}
		delete temp;
		temp = nullptr;
	}
	else {
		EXPECT_TRUE(false);
	}
}
