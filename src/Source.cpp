#include <iostream>
#include "UserControl.h"
#include "Editor.h"
using namespace std;

int main(int argc, char* argv[])
{

	const int WINDOW_WIDTH = 800;
	const int WINDOW_HEIGHT = 600;

	Editor editor;
	UserControl userControl;
	editor.Initialize(WINDOW_WIDTH, WINDOW_HEIGHT, 0);

	//Main loop
	while (editor.IsRunning())
	{
		editor.Update();
		editor.Render();
		userControl.ProcessInput();
	}

	return 0;
}
