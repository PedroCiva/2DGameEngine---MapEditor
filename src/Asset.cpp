#include "Asset.h"
#include "TextureManager.h"


void Asset::Render()
{
	SDL_RenderCopyEx(Editor::renderer, texture, &sourceRect, &destRect, 0.0, NULL, SDL_FLIP_NONE);
}

Asset::Asset(std::string name,string spritePath,int posX,int posY)
{
	this->name = name;
	this->destRect.x = posX;
	this->destRect.y = posY;
	this->texture = TextureManager::GetTexture(spritePath);
}