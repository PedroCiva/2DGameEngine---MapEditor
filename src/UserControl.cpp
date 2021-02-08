#include "UserControl.h"
#include "AssetManager.h"
#include "Asset.h"

void UserControl::ProcessInput()
{
	for (auto asset : AssetManager::GetInstance()->assets)
	{
		//Fetch mouse position
		SDL_PumpEvents();
		SDL_GetMouseState(&mousePos.x, &mousePos.y);
		//To-Do
		//Add a for loop to loop through the destination rects (positions) of all sprites and check
		if ((mousePos.x - 10 >= asset.second->destRect.x - 20 && mousePos.x - 10 <= asset.second->destRect.x + 20) && (mousePos.y - 10 >= asset.second->destRect.y - 20 && mousePos.y - 10 <= asset.second->destRect.y + 20))
		{
			if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT)) {
				DragAndDrop(asset.second->destRect);
			}
		}
	}
}

void UserControl::DragAndDrop(SDL_Rect &destRect)
{
	destRect.x = mousePos.x - 10;
	destRect.y = mousePos.y - 10;
}
