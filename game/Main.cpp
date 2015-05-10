#include <iostream>
#include <thread>

#ifndef SDL_MAIN_HANDLED
#define SDL_MAIN_HANDLED
#endif

#include "Log.h"
#include "World.h"
#include "ConsoleHandler.h"

using namespace std;
using namespace lunk;

Log _log;

int main(int argc, char **argv) {
	Engine::Params params;
	params.screenWidth = 800;
	params.screenHeight = 600;
	params.windowTitle = "Lunk's Awakening";

	Engine *engine = new Engine{params};

	engine->initializeEngine();

	if (!engine->isInitialized())
		return -1;

	_log.INFO() << "Running engine from: "
	<< engine->getFilesystem()->getCurrentWorkingDirectory()
	<< endl;

	World *worldPtr = new World(engine, nullptr);

	engine->registerUpdateable(worldPtr);
	engine->registerRenderable(worldPtr);

	ConsoleHandler consoleHandler{worldPtr};

	consoleHandler.start();

	engine->start();

	consoleHandler.stop();

	engine->stop();

	return 0;
}