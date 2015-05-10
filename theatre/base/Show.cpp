#include <Animator.h>
#include "Show.h"

#include "Log.h"

using namespace lunk;

static Log _log;

Show::Show(lunk::Engine *game, lunk::TileEngine *tileEngine)
		: tileEngine(tileEngine),
		  engine(game) {

}

void Show::render(lunk::Renderer *renderer) {
	for (auto &worldObj : acts) {
		worldObj->render(renderer);
	}
}

void Show::update(double timeDelta) {
	for (auto &worldObj : acts) {
		worldObj->update(timeDelta);
	}
}

void Show::registerAct(Act *obj) {
	acts.push_back(obj);
}

lunk::Engine *Show::getEngine() {
	return engine;
}

lunk::Vec2 Show::getCameraPosition() {
	return position;
}
