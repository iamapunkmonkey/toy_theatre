#pragma once

#include <string>
#include <vector>
#include <SDL.h>

#include "Filesystem.h"
#include "Input.h"
#include "Renderer.h"
#include "Random.h"
#include "Sound.h"
#include "TextureFactory.h"
#include "LunkTimer.h"

namespace lunk {
	class Updateable;

	class Renderable;

	class Engine {
	public:
		struct Params {
			int screenWidth;
			int screenHeight;
			std::string windowTitle;
		};

	public:

		Engine(const Params &params);

		Engine(const Engine &other);

		~Engine();

		void start();

		void stop();

		SDL_Window *getWindow() const {
			return mainWindow;
		}

		int getScreenHeight() const {
			return frameBuffer->h;
		}

		int getScreenWidth() const {
			return frameBuffer->w;
		}

		bool isInitialized() const {
			return initialized;
		}

		Filesystem *getFilesystem() {
			return filesystem;
		}

		Renderer *getRenderer() {
			return renderer;
		}

		TextureFactory *getTextureFactory() {
			return imageFactory;
		}

		Random *getRandom() {
			return random;
		}

		Sound *getSound() {
			return sound;
		}

		Input *getInput() {
			return input;
		}

		int getFrameCount() const {
			return frameCount;
		}

		void setRunning(bool running) {
			this->running = running;
		}

		void startFrame();

		void endFrame();

		void update();

		void registerUpdateable(Updateable *);

		void registerRenderable(Renderable *);

		bool initializeEngine();

	private:
		bool initSDL();

		void stopSDL();

		bool initSDLImage();

		void stopSDLImage();

		bool initSDLTTF();

		void stopSDLTTF();

		SDL_Window *mainWindow;
		SDL_Surface *frameBuffer;

		Random *random;

		Renderer *renderer;

		Sound *sound;

		Filesystem *filesystem;

		TextureFactory *imageFactory;

		Input *input;

		bool initialized = false;

		int frameCount = 0;

		double lastFrameTimeDelta = 0;

		std::vector<Updateable *> registeredUpdateables;

		std::vector<Renderable *> registeredRenderables;

		LunkTimer frameTimer;

		LunkTimer gameTimer;

		const Params initParams;

		bool running;
	};
}