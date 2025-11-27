#pragma once

#include <iostream>

#include "../glad.h" 

class KMD_GL_Shader;

class KMD_GL_ShaderProgram {
public:

	unsigned int ShaderProgramID = 0;

	KMD_GL_ShaderProgram() {};

	void Create(KMD_GL_Shader vertex_shader, KMD_GL_Shader fragment_shader);

	void Use() {

		glUseProgram(ShaderProgramID);
	}
};