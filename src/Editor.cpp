#include "Editor.h"
#include "AssetManager.h"
#include "Asset.h"
#include "MapWindow.h"
#include <SDL_ttf.h>

using namespace std;

MapWindow Editor::mapWindow(300, 25, 400, 400);

Editor::Editor() 
{
	this->isRunning = false;
};

Editor::~Editor() {};

bool Editor::IsRunning() const
{
	return this->isRunning;
}

//Creating window and renderer and loading the level
void Editor::Initialize(int width,int height, int levelID)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		cout << "Error initializing SDL" << endl;
		cout << SDL_GetError();
		return;
	}
		

	if (TTF_Init() != 0)
	{
		cerr << "Error initializing SDL_TTF" << std::endl; 
		cout << SDL_GetError() << endl;
		return;
	}
		

	window = SDL_CreateWindow("Map Editor", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, NULL);
	if (!window) 
	{
		cerr << "Error initializing SDL window..." << endl;
		cout << SDL_GetError() << endl;
		return;
	}
		

	renderer = SDL_CreateRenderer(window, -1, NULL);
	if (!renderer)
	{
		cerr << "Error initializing SDL renderer..." << endl;
		cout << SDL_GetError() << endl;
		return;
	}

	LoadEditor();
	this->isRunning = true;
}

void Editor::Update()
{
	int ticksLastFrame = 0;
	int targetFPS = 144;
	const int FRAME_TARGET_TIME = 1000 / targetFPS;
	//Wait until 16.6ms (target frame rate) has ellapsed since the last frame, so it looks the same on every computer
	int timeToWait = FRAME_TARGET_TIME - (SDL_GetTicks() - ticksLastFrame);

	if (timeToWait > 0 && timeToWait <= FRAME_TARGET_TIME)
		SDL_Delay(timeToWait);


	//Delta time is the difference in ticks from last frame converted to seconds
	float deltaTime = (SDL_GetTicks() - ticksLastFrame) / 1000.0f;

	//Clamp deltaTime to a maximum value, in case we debug with breakpoints it won't cause weird issues in our game due to excessive deltaTime 
	deltaTime = (deltaTime > 0.05f) ? 0.05f : deltaTime;

	//Sets the new ticks time for the current frame to be used in the next pass
	ticksLastFrame = SDL_GetTicks();
	HandleCameraMovement();
}

void Editor::Render()
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	for (auto asset : AssetManager::GetInstance()->assets)
	{
		asset.second->Render();
	}

	SDL_SetRenderDrawColor(renderer, 169, 169, 169, 255);
	mapWindow.Render(renderer);

	//Swap backbuffer
	SDL_RenderPresent(renderer);
}

void::Editor::HandleCameraMovement()
{
	//To-Do
}

//Loads main editor
void Editor::LoadEditor()
{
	AssetManager::GetInstance()->AddAsset("tank_Main", "Sprites/tank-tiger-right.png", 500, 500,true);
	//AssetManager::GetInstance()->AddAsset("tile1_Main","Sprites)
}





