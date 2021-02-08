#pragma once
#include "Structs.h"
#include <SDL.h>

//Functionality for the user controls, such as drag and drop etc...
class UserControl
{
private:
	vec2 mousePos;

public:
	void ProcessInput();
	void DragAndDrop(SDL_Rect & destRect);
};
