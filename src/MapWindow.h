#pragma once
#include <iostream>
#include <SDL.h>

class MapWindow {
private:

	
public:
	SDL_Rect windowRect;

	MapWindow(int posX, int posY, int width, int height)
	{
		windowRect.x = posX;
		windowRect.y = posY;
		windowRect.w = width;
		windowRect.h = height;
	}

	void Render(SDL_Renderer* renderer)
	{
		SDL_RenderDrawRect(renderer, &windowRect);
	}
};