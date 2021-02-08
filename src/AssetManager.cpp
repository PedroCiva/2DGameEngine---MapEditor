#include "AssetManager.h"
#include "Asset.h"


//Initializing static instance manually
//AssetManager* AssetManager::_instance = nullptr;

void AssetManager::AddAsset(std::string name, std::string spritePath, int posX, int posY)
{
	Asset* asset = new Asset(name, spritePath, posX, posY);
	std::pair<std::string, Asset*> assetPair(asset->name, asset);
	assets.insert(assetPair);
}

Asset* AssetManager::GetAsset(std::string name)
{
	return this->assets[name];
}

