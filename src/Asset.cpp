#include "Asset.h"
#include "AssetManager.h"
#include "TextureManager.h"


void Asset::Render()
{
	SDL_RenderCopyEx(Editor::renderer, texture, &sourceRect, &destRect, 0.0, NULL, SDL_FLIP_NONE);
}

void Asset::Destroy()
{
	AssetManager::GetInstance()->assets.erase(this->name);
}

Asset::Asset(std::string name,string spritePath,int posX,int posY,bool isReference)
{
	this->name = name;
	this->destRect.x = posX;
	this->destRect.y = posY;
	this->isReference = isReference;
	this->texture = TextureManager::GetTexture(spritePath);
}