#pragma once

#include <algorithm>
#include <sstream>
#include <vector>

#include "Renderable.h"
#include "Updateable.h"

#include "TileEngine.h"
#include "Vec2.h"
#include "Sound.h"
#include "Engine.h"

#include "List.h"
#include "Act.h"

class Show : public lunk::Updateable, public lunk::Renderable {
public:
	Show(lunk::Engine *game, lunk::TileEngine *tileEngine);

	void update(double timeDelta) override;

	void render(lunk::Renderer *renderer) override;

	void registerAct(Act*);

	lunk::Engine *getEngine();

	lunk::Vec2 getCameraPosition();

private:
	lunk::Vec2 position;
	lunk::Engine *engine;
	lunk::TileEngine *tileEngine;
	std::vector<Act *> acts;
};