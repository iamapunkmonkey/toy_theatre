#pragma once

#include <SDL_image.h>
#include <string>

#include "Texture.h"

namespace lunk {
	class TextureFactory {
	public:
		virtual lunk::Texture *loadTextureFromImage(std::string filename) = 0;
	};
}