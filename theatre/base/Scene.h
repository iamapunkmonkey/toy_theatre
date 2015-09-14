#pragma once

#include "WorldObject.h"
#include "Act.h"

using namespace lunk;

class WorldObject;

class Act;

class Scene {
public:
	Scene(Act *act) : act(act) { }

	void update(double timeDelta, int frame);

	void render(lunk::Renderer *renderer);

	void registerObject(WorldObject *);

	Act *getAct();

private:
	std::vector<WorldObject *> worldObjects;
	Act *act;
};