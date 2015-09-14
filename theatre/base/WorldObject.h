#pragma once

#include "Entity.h"
#include "Vec2.h"
#include "Renderable.h"
#include "Show.h"

using namespace lunk;

class Show;
class WorldObject {
public:
	WorldObject(Show *world) : world(world) { };

	virtual void update(double, int) = 0;

	virtual void render(Renderer *) = 0;

protected:
	Show *world;
};