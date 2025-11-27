#pragma once

#include <iostream>

#include "../Vectors/Vector2.h"
#include "../Vectors/IVector2.h"

#include "../Color/Color.h"

#include "../../KMD2/Renderer/Renderer.h"

#include <SDL3/SDL.h>

//
// Nucleo do jogo
//

class KMD_Core {
public:

	SDL_Window* Window = nullptr;
	KMD_Renderer* Renderer = nullptr;

	SDL_Event Event = {};

	bool Running = true;
	bool DebugOut = true;

	//

	ivector2 WindowSize = ivector2::Zero();

	//

	KMD_Core(std::string title, ivector2 window_size, color4 background_color, SDL_WindowFlags flags) : WindowSize(window_size) {

		SDL_Init(SDL_INIT_VIDEO);

		Window = SDL_CreateWindow(title.c_str(), WindowSize.X, WindowSize.Y, SDL_WINDOW_OPENGL | flags);
		Renderer = new KMD_Renderer(Window, background_color);

		_Ready();
	}

	virtual ~KMD_Core() {

		SDL_DestroyWindow(Window);
		delete Renderer;

		SDL_Quit();
	}

	//

	virtual void _Ready() {}

	virtual void _Input(InputEvent Input) {}

	virtual void _Process(double Delta) {}

	virtual void _Finish() {}
};