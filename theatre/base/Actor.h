#pragma once

#include <unordered_map>

#include "WorldObject.h"

using namespace lunk;

class Action;

class Actor : public WorldObject {
public:
	Actor(Show *world) : WorldObject(world) {
//		_actions = new std::unordered_map<long, Action>();
	}

	void update(double, int) override;

	void render(Renderer *) override;

private:
//	std::unordered_map<long, Action> *_actions;
};