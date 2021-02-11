#pragma once
#include <iostream>
#include <SDL.h>
using namespace std;

struct vec2
{
public:
	int x;
	int y;
	vec2() {};
	vec2(int x, int y) {
		x = x, y = y;
	}
};

	/// <summary>
	/// Gets mouse position in relation to the specified rectangle
	/// </summary>	
class Methods {
public:

	static vec2 GetRelativeMousePosition(SDL_Rect& rect)
	{
		int mousePosX, mousePosY;
		SDL_GetMouseState(&mousePosX, &mousePosY);
		if (mousePosX > rect.x && mousePosY > rect.y)
		{
			//Inside the rect
			int relativePosX = mousePosX - rect.x;
			int relativePosY = mousePosY - rect.y;
			cout << "Relative Pos X: " << relativePosX << "   Relative Pos Y: " << relativePosY << endl;
			return vec2(relativePosX, relativePosY);
		}
		else
		{
			return vec2(0, 0);
		}
	}

};

	

