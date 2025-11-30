#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

#include <iostream>

#include "../glad.h"

class KMD_GL_Texture {
public:

	unsigned int TextureID = 0;

	SDL_Surface* Surface = nullptr;

	KMD_GL_Texture() {}

	void Create(std::string path, GLenum filter) {

		Surface = IMG_Load((path).c_str());

		if (!Surface) {

			std::cerr << "KMD_GL_Texture: Erro ao carregar Surface: " + path + "\n\n" << SDL_GetError() << "\n\n";
			return;
		}

		glGenTextures(1, &TextureID);
		glBindTexture(GL_TEXTURE_2D, TextureID);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, filter);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filter);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, Surface->w, Surface->h, 0, GL_RGBA, GL_UNSIGNED_BYTE, Surface->pixels);
		glGenerateMipmap(GL_TEXTURE_2D);

		SDL_DestroySurface(Surface);
	}

	void Bind() {

		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, TextureID);
	}
};