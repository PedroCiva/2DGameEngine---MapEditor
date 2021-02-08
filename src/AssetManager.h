#pragma once
#include <iostream>
#include <unordered_map>

class Asset;

class AssetManager {

private:
	inline static AssetManager* _instance; // using inline to initialize this static instance here, for an example without inline, check the .cpp

public:
	static AssetManager* GetInstance()
	{
		if (!_instance)
			_instance = new AssetManager();
		return _instance;
	}

	std::unordered_map<std::string, Asset*> assets;


	void AddAsset(std::string name, std::string spritePath, int posX, int posY);
	Asset* GetAsset(std::string id);

};
