#pragma once

#include "WorldObject.h"

using namespace lunk;

class Actor : public WorldObject {
public:
	Actor(Show *world) : WorldObject(world) { }

	void update(double) override;

	void render(Renderer *) override;
};