#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>


class TextureManager
{
public:
	static SDL_Texture* GetTexture(std::string spritePath)
	{
		SDL_Surface* surface = IMG_Load(spritePath.c_str());
		if(surface==NULL)
			printf("IMG_Load: %s\n", IMG_GetError());

		SDL_Texture* texture = SDL_CreateTextureFromSurface(Editor::renderer, surface);
		SDL_FreeSurface(surface);
		return texture;
	}
};
