#include "ShaderProgram.h"

#include "Shader.h"

void KMD_GL_ShaderProgram::Create(KMD_GL_Shader vertex_shader, KMD_GL_Shader fragment_shader) {

	ShaderProgramID = glCreateProgram();

	VertexShaderID = vertex_shader.ShaderID;
	FragmentShaderID = fragment_shader.ShaderID;

	glAttachShader(ShaderProgramID, vertex_shader.ShaderID);
	glAttachShader(ShaderProgramID, fragment_shader.ShaderID);

	glLinkProgram(ShaderProgramID);

	//

	int Sucess;
	char InfoLog[512];

	glGetProgramiv(ShaderProgramID, GL_LINK_STATUS, &Sucess);

	if (!Sucess) {

		glGetProgramInfoLog(ShaderProgramID, 512, NULL, InfoLog);
		std::cerr << "Erro ao linkar shaders:\n\n" << InfoLog << "\n\n";
	}
}