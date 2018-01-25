#pragma once

#ifdef TEXTUREFILTERDLL_EXPORTS
#define TEXTUREFILTERDLL_API __declspec(dllexport) 
#else
#define TEXTUREFILTERDLL_API __declspec(dllimport) 
#endif

#pragma comment(lib,"SDL2.lib") 
#pragma comment(lib, "SDL2_image.lib")

#include <map>
#include <SDL.h>
#include <SDL_image.h>
#include "JTexture.h"
#include "TextureEffect.h"
class TextureFilter
{
public:

	enum EdgeType
	{
		EdgeEnhance,
		EdgeDetect,
		Emboss
	};

	TEXTUREFILTERDLL_API static TextureFilter * Instance();
	TEXTUREFILTERDLL_API bool TextureFilter::createJtexture(std::string fileName, int id, SDL_Renderer* renderer);
	TEXTUREFILTERDLL_API SDL_Texture* getTexture(int id);
	TEXTUREFILTERDLL_API SDL_Rect getTextureBounds(int id);

	// TEXTURE FILTERS
	//////////////////////////////////
	// Texture ID
	TEXTUREFILTERDLL_API void grayscaleFilter(int id);
	// Texture ID, Threshold 0 - 255, Blur Radius, Blend Amount 0-1.f
	TEXTUREFILTERDLL_API void bloomFilter(int id, int threshold, int radius, float blendAmount);
	// Texture ID, Type 0-EdgeEnhance, 1-EdgeDetect, 2-Emboss
	TEXTUREFILTERDLL_API void edgeDectection(int id, int type);
	// Texture ID, Pixel Size
	TEXTUREFILTERDLL_API void pixelateFilter(int id, int pixelSize);
	// Texture ID, Blur Radius
	TEXTUREFILTERDLL_API void gaussianBlur1D(int id, int radius);
	// Texture ID
	TEXTUREFILTERDLL_API void resetPixels(int id);

private:
	const float MAX_BLEND_AMOUNT = 1.0f;
	const int MAX_THRESHOLD = 255;
	const int MAX_BLUR_RADIUS = 100;
	const int MAX_PIXEL_SIZE = 100;
	static TextureFilter *m_inst;
	std::map<int, JTexture*> m_textureMap;
	TEXTUREFILTERDLL_API TextureFilter();
	TEXTUREFILTERDLL_API ~TextureFilter();

};
