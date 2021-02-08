#pragma once
#include <iostream>
#include <SDL.h>
#include "Editor.h"

using namespace std;

//Holds data about an asset
class Asset {
private:
	SDL_Texture* texture; //The texture for this asset


public:
	Asset(string name, string spritePath,int posX, int posY);
	~Asset();
	string name;

	bool isPlaced; //Has this asset been placed on the map or not
	bool isDraggable; //Is this asset draggable?
	bool isSelectable; //Is this asset selectable?

	void Render();

	//Should I be initializing these values here?
	SDL_Rect sourceRect{
		sourceRect.x = 0,
		sourceRect.y = 0,
		sourceRect.w = 32,
		sourceRect.h = 32
	};

	SDL_Rect destRect{
		destRect.x = 0,
		destRect.y = 0,
		destRect.w = 32,
		destRect.h = 32
	};

};
