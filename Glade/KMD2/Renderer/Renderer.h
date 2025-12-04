#pragma once

#include "../../Glad/glad.h"
#include "SDL3/SDL.h"

#include "../../Glad/KMD2/VBO.h"
#include "../../Glad/KMD2/VAO.h"

#include "../../Glad/KMD2/ShaderProgram.h"

#include <fstream>
#include <sstream>

#include <iostream>

#include "../Color/Color.h"

class KMD_Renderer {
private:

	SDL_GLContext GlContext = {};

public:

	color4 BackgroundColor = color4::Black();

	//

	KMD_Renderer(SDL_Window* window, color4 background_color): BackgroundColor(background_color) {

		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

		GlContext = SDL_GL_CreateContext(window);
		SDL_GL_MakeCurrent(window, GlContext);

		gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress);
	}

	~KMD_Renderer() {

		SDL_GL_DestroyContext(GlContext);
	}

	//

	void Clear() {
		
		glClearColor(BackgroundColor.R, BackgroundColor.G, BackgroundColor.B, BackgroundColor.A);
		glClear(GL_COLOR_BUFFER_BIT);
	}

	void Swap(SDL_Window* Window) {

		SDL_GL_SwapWindow(Window);
	}

	//

	static std::string OpenGLSL(const std::string Path) {

		std::ifstream File(Path);

		if (!File.is_open()) {

			std::cerr << "KMD::Renderer: Erro ao abrir arquivo: " << Path << "\n";
			return "";
		}

		std::stringstream Buffer;
		Buffer << File.rdbuf();

		File.close();

		return Buffer.str();
	};
};