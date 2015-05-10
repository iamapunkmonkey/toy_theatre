#include <Animator.h>
#include "World.h"

#include "Log.h"

using namespace lunk;

static Log _log;

World::World(lunk::Engine *game, lunk::TileEngine *tileEngine)
		: tileEngine(tileEngine),
		  engine(game) {
}

void World::render(lunk::Renderer *renderer) {

}

void World::update(double timeDelta) {

}


lunk::Engine *World::getEngine() {
	return engine;
}

lunk::Vec2 World::getCameraPosition() {
	return position;
}
