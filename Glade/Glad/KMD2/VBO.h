#pragma once

#include "../glad.h"

class KMD_GL_VertexBufferObject {
public:

	unsigned int VBO = 0;

	GLenum Target;
	GLenum Usage;

	size_t Size;
	const void* Data;

	KMD_GL_VertexBufferObject(const GLenum target, size_t size, const void* data, const GLenum usage) : Target(target), Size(size), Data(data), Usage(usage) {};

	void Gen() {

		glGenBuffers(1, &VBO);
		Bind();
	}

	void Delete() {

		glDeleteBuffers(1, &VBO);
	}

	void Bind() {

		glBindBuffer(Target, VBO);
		glBufferData(Target, Size, Data, Usage);
	};
};