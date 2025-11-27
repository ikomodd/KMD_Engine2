#pragma once

#include "../glad.h"
#include "VBO.h"

class KMD_GL_VertexArrayObject {
public:

	unsigned int VAO = 0;

	//

	KMD_GL_VertexArrayObject() {}

	//

	void Gen() {

		glGenVertexArrays(1, &VAO);
		Bind();
	}

	void Bind() {

		glBindVertexArray(VAO);

	}

	void AddAttribute(const GLuint location, const size_t size, const GLenum type, const GLboolean normalized, const GLsizei stride, const void* pointer) {

		glVertexAttribPointer(location, size, type, normalized, stride, pointer);
		glEnableVertexAttribArray(location);
	}
};