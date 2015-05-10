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


class World : public lunk::Updateable, public lunk::Renderable {
public:
	World(lunk::Engine *game, lunk::TileEngine *tileEngine);

	void update(double timeDelta) override;

	void render(lunk::Renderer *renderer) override;

	lunk::Engine *getEngine();

	lunk::Vec2 getCameraPosition();

private:
	lunk::Vec2 position;
	lunk::Engine *engine;
	lunk::TileEngine *tileEngine;
};