#include "Renderer.h"

#include <iostream>

#include "../../Glad/KMD2/Shader.h"

KMD_Renderer::KMD_Renderer(SDL_Window* window, color4 background_color) : BackgroundColor(background_color) {

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

	GlContext = SDL_GL_CreateContext(window);
	SDL_GL_MakeCurrent(window, GlContext);

	gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress);

	//
	
	VBO.Gen();
	VAO.Gen();

	VAO.AddAttribute(0, 3, GL_FLOAT, GL_FALSE, sizeof(float), (void*)0);

	//

	KMD_GL_Shader VertexShader(GL_VERTEX_SHADER, "StartVertexShader.glsl");
	KMD_GL_Shader FragmentShader(GL_FRAGMENT_SHADER, "StartFragmentShader.glsl");

	ShaderProgram.Create(VertexShader, FragmentShader);
}