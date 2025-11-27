#include <iostream>

#include "Glad/glad.h"
#include "SDL3/SDL.h"

#include "KMD2/Core/Core.h"
#include "Game.h"

int main() {

	GameCore* Game = new GameCore();

	Uint64 LastDeltaTick = SDL_GetTicks();

	while (Game->Running)
	{
		while (SDL_PollEvent(&Game->Event)) {

			InputEvent Input = {};

			if (Game->Event.type == SDL_EVENT_QUIT) Input.Type = InputType::QUIT;

			Game->_Input(Input);
		}

		Uint64 CurrentDeltaTick = SDL_GetTicks();
		double Delta = (CurrentDeltaTick - LastDeltaTick) * 1000.0;
		LastDeltaTick = CurrentDeltaTick;

		Game->_Process(Delta);
	}

	return 1;
}