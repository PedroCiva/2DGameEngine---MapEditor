#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

//Contains all basic methods and variables for the main loop
class Editor
{
private:
	bool isRunning;
	SDL_Window* window;

public:
	Editor();
	~Editor();
	int ticksLastFrame = 0;
	bool IsRunning() const;
	
	inline static SDL_Renderer* renderer;
	static SDL_Event eventHandler;
	static SDL_Rect camera;

	//Initializes SDL window
	void Initialize(int width, int height, int levelID);
	void ProcessInput();
	void LoadEditor();
	void LoadLevel(int levelID);
	void Update();
	void Render();
	void Destroy();
	void HandleCameraMovement();

};

