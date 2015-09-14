#include "Engine.h"

#include <SDL_ttf.h>
#include <sdl/SDLRenderer.h>
#include <thread>

#include "Log.h"
#include "sdl/SDLInput.h"
#include "sdl/SDLTextureFactory.h"
#include "Updateable.h"
#include "Renderable.h"

static lunk::Log _log;

namespace lunk {
	Engine::Engine(const Params &params) : initParams(params) {
//		frameTimer = LunkTimer();
	}

	Engine::~Engine() {
		SDL_DestroyWindow(mainWindow);
		mainWindow = nullptr;
	}

	bool Engine::initializeEngine() {
		using namespace std;

		if (!initSDL())
			return false;

		if (!initSDLImage())
			return false;

		if (!initSDLTTF())
			return false;

		sound = new Sound();
		sound->initialize();

		mainWindow = SDL_CreateWindow(initParams.windowTitle.c_str(), 1000, SDL_WINDOWPOS_UNDEFINED,
									  initParams.screenWidth, initParams.screenHeight, SDL_WINDOW_SHOWN);

		if (mainWindow == nullptr) {
			_log.ERROR() << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
			return false;
		}

		SDL_Renderer *nativeRenderer = SDL_CreateRenderer(getWindow(), -1,
														  SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

		frameBuffer = SDL_GetWindowSurface(mainWindow);

		renderer = new SDLRenderer{nativeRenderer};

		imageFactory = new SDLTextureFactory(renderer);

		input = new SDLInput();

		random = new Random();

		initialized = true;

		running = true;

		return true;
	}

	void Engine::stop() {
		if (initialized) {
			stopSDLTTF();
			stopSDLImage();
			stopSDL();

			initialized = false;
		}
	}

	bool Engine::initSDL() {
		if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_NOPARACHUTE) < 0) {
			_log.ERROR() << "Could not init SDL_VIDEO" << std::endl;
			return false;
		}

		return true;
	}

	bool Engine::initSDLImage() {
		int flags = IMG_INIT_PNG;

		int status = IMG_Init(flags);
		if ((status & flags) != flags) {
			_log.ERROR() << "IMG_Init: Failed to init required png support!" << std::endl;
			_log.ERROR() << "IMG_Init: " << IMG_GetError() << std::endl;
			return false;
		}

		return true;
	}

	bool Engine::initSDLTTF() {
		return TTF_Init() == 0;
	}

	void Engine::registerUpdateable(Updateable *updateable) {
		registeredUpdateables.push_back(updateable);
	}

	void Engine::registerRenderable(Renderable *drawable) {
		registeredRenderables.push_back(drawable);
	}

	void Engine::startFrame() {
		frameTimer.restart();
	}

	void Engine::endFrame() {
		frameCount += 1;
		renderer->flip();

		lastFrameTimeDelta = frameTimer.seconds();
	}

	void Engine::update() {
//        lastFrameTimeDelta = 15;

		input->update();

		for (auto &updateable : registeredUpdateables) {
			updateable->update(lastFrameTimeDelta, frameCount);
		}

		// Draw
		renderer->setColor(0xffffffff);
		renderer->clear();

		for (auto &drawable : registeredRenderables) {
			drawable->render(renderer);
		}

		// TODO: Not the best solution, to come back to.
		if (input->windowClosedRequest()) {
			running = false;
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}

	void Engine::stopSDL() {
		SDL_Quit();
	}

	void Engine::stopSDLImage() {
		IMG_Quit();
	}

	void Engine::stopSDLTTF() {
		TTF_Quit();
	}

	void Engine::start() {
		while (running) {
			startFrame();

			update();

			endFrame();
		}

	}
}