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

	float Rect[9] = {

		0.0f, 0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
	};

	SDL_GLContext GlContext = {};

public:

	KMD_GL_ShaderProgram ShaderProgram;

	KMD_GL_VertexBufferObject VBO = KMD_GL_VertexBufferObject(GL_ARRAY_BUFFER, sizeof(Rect), Rect, GL_STATIC_DRAW);
	KMD_GL_VertexArrayObject VAO;

	color4 BackgroundColor = color4::Black();

	//

	KMD_Renderer(SDL_Window* window, color4 background_color);

	~KMD_Renderer() {

		SDL_GL_DestroyContext(GlContext);
	}

	//

	void Clear() {
		
		glClearColor(BackgroundColor.R, BackgroundColor.G, BackgroundColor.B, BackgroundColor.A);
		glClear(GL_COLOR_BUFFER_BIT);
	}

	void Draw(SDL_Window* Window) {

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