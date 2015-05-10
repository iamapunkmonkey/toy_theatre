#pragma once

#include "Entity.h"
#include "Vec2.h"
#include "Renderable.h"
#include "World.h"

using namespace lunk;

class WorldObject {
public:
	WorldObject(World *world) : world(world) { };

	virtual void update(double) = 0;

	virtual void render(Renderer *) = 0;

protected:
	World *world;
};