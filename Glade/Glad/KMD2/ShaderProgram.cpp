#include "ShaderProgram.h"

#include "Shader.h"

void KMD_GL_ShaderProgram::Create(KMD_GL_Shader vertex_shader, KMD_GL_Shader fragment_shader) {

	glAttachShader(ShaderProgramID, vertex_shader.ShaderID);
	glAttachShader(ShaderProgramID, fragment_shader.ShaderID);

	glLinkProgram(ShaderProgramID);
}