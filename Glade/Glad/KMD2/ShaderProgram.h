#pragma once

#include <iostream>

#include "../glad.h" 

class KMD_GL_Shader;

class KMD_GL_ShaderProgram {
private:

	unsigned int VertexShaderID = 0;
	unsigned int FragmentShaderID = 0;

public:

	unsigned int ShaderProgramID = 0;

	KMD_GL_ShaderProgram() {};

	void Create(KMD_GL_Shader vertex_shader, KMD_GL_Shader fragment_shader);

	void Delete() {

		glDeleteShader(FragmentShaderID);
		glDeleteShader(VertexShaderID);

		glDeleteProgram(ShaderProgramID);
	}

	void Use() {

		glUseProgram(ShaderProgramID);
	}
};