#pragma once

#include <SDL3/SDL.h>

struct color4 {

	unsigned int R;
	unsigned int G;
	unsigned int B;
	unsigned int A;
	
	static color4 Black() {

		return color4(0, 0, 0, 255);
	}

	static color4 White() {

		return color4(255, 255, 255, 255);
	}

	static void SetRenderDrawColor(SDL_Renderer* Renderer, color4 Color) {

		SDL_SetRenderDrawColor(Renderer, Color.R, Color.G, Color.B, Color.A);
	}
	
	color4(unsigned int R = 0, unsigned int G = 0, unsigned int B = 0, unsigned int A = 0): R(R), G(G), B(B), A(A) {}
};