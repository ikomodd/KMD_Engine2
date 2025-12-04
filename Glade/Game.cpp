#include "Game.h"

void GameCore::_Ready() {

	// Seu Script

}

void GameCore::_Input(SDL_Event event) {

	if (event.type == SDL_EVENT_QUIT) _Finish();
	else if (event.type == SDL_EVENT_WINDOW_RESIZED) {

		SDL_GetWindowSize(Window, &WindowSize.X, &WindowSize.Y);
		glViewport(0, 0, WindowSize.X, WindowSize.Y);
	}

	// Seu Script

}

void GameCore::_Process(double Delta) {

	Renderer->Clear();

	// Seu Script

	Renderer->Swap(Window);
}

void GameCore::_Finish() {

	// Seu Script

	Running = false;
}