#include "UserControl.h"
#include "AssetManager.h"
#include "Asset.h"

void UserControl::ProcessInput()
{
	SDL_PumpEvents();
	SDL_GetMouseState(&mousePos.x, &mousePos.y);
	if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT)) 
	{
		for (auto asset : AssetManager::GetInstance()->assets)
		{
			if ((mousePos.x - 10 >= asset.second->destRect.x - 20 && mousePos.x - 10 <= asset.second->destRect.x + 20) && (mousePos.y - 10 >= asset.second->destRect.y - 20 && mousePos.y - 10 <= asset.second->destRect.y + 20))
			{
				DragAndDrop(asset.second->destRect);
			}
		}	
	}
	else if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_RIGHT))
	{
		for (auto asset : AssetManager::GetInstance()->assets)
		{
			if ((mousePos.x - 10 >= asset.second->destRect.x - 20 && mousePos.x - 10 <= asset.second->destRect.x + 20) && (mousePos.y - 10 >= asset.second->destRect.y - 20 && mousePos.y - 10 <= asset.second->destRect.y + 20))
			{
				asset.second->Destroy();
				break;
			}
		}
	}
}

void UserControl::DragAndDrop(SDL_Rect &destRect)
{
	destRect.x = mousePos.x - 10;
	destRect.y = mousePos.y - 10;
}

