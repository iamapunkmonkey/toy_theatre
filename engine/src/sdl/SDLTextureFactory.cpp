#include "sdl/SDLTextureFactory.h"

#include "Log.h"

#include "sdl/SDLTexture.h"

static lunk::Log _log;

namespace lunk {
	SDLTextureFactory::SDLTextureFactory(Renderer *renderer) : renderer(renderer) {
	}

	lunk::Texture *SDLTextureFactory::loadTextureFromImage(std::string filename) {
		SDL_Surface *rawSurface = IMG_Load(filename.c_str());

		if (rawSurface == nullptr) {
			_log.ERROR() << "Could not load surface" << filename << "\n";
			_log.ERROR() << "IMG_Load: " << IMG_GetError() << "\n";
			return nullptr;
		}

		SDL_Texture *sdlTexture = SDL_CreateTextureFromSurface((SDL_Renderer *) renderer->getNativeRenderer(),
															   rawSurface);

		SDLTexture *texture = new SDLTexture{sdlTexture};
		Texture *result = texture;

		return result;
	}
}

