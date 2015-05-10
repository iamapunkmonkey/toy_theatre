#pragma once

#include <Renderer.h>
#include <Vec2.h>

static const int TILE_SIZE = 32;
static const double TOP_MIN = 300.0;

class Background {
public:
	Background();

	void Render(lunk::Renderer *renderer, lunk::Vec2 worldPos);

	void update(double timeDelta);

private:
	lunk::Texture *sprite_sheet;
};