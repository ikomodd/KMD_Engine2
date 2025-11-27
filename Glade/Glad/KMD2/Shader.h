#pragma once

#include <iostream>

#include "../glad.h" 
#include "../../KMD2/Renderer/Renderer.h"

class KMD_GL_Shader {
public:

	unsigned int ShaderID;

	KMD_GL_Shader(const GLenum type, const char* path) {

		ShaderID = glCreateShader(type);

		std::string ShaderSourceStr = KMD_Renderer::OpenGLSL(path);
		const char* ShaderSource = ShaderSourceStr.c_str();

		glShaderSource(ShaderID, 1, &ShaderSource, NULL);
		glCompileShader(ShaderID);

		int Sucess;
		char InfoLog[512];
		glGetShaderiv(ShaderID, GL_COMPILE_STATUS, &Sucess);

		if (!Sucess) {

			glGetShaderInfoLog(ShaderID, 512, NULL, InfoLog);

			std::cerr << "KMD::Shader: Erro ao compilar shader: " << path << ":\n\n" << InfoLog << "\n\n";
		}
	}
};