#pragma once

#include "Renderer.h"
#include "TextureFactory.h"

namespace lunk {
	class SDLTextureFactory : public TextureFactory {
	public:
		SDLTextureFactory(Renderer *renderer);

		SDLTextureFactory(const TextureFactory &other);

		SDLTextureFactory operator=(const TextureFactory &other);

		lunk::Texture *loadTextureFromImage(std::string filename) override;

	private:
		Renderer *renderer;
	};
}