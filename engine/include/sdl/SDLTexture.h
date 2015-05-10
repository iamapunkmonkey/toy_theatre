#pragma once

#include "Texture.h"

struct SDL_Texture;

namespace lunk {
	class Vec2;

	class SDLTexture : public Texture {
	public:
		SDLTexture(void *texture);

		SDLTexture(const SDLTexture &other);

		~SDLTexture();

		void *getNative() const override;

		Vec2 getSize() const override;

	private:
		struct Implementation;

		Implementation *impl;
	};
}