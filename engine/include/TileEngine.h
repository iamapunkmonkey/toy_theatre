#pragma once

#include "Renderer.h"
#include "Rect2.h"
#include "Texture.h"
#include "TileMap.h"
#include "Vec2.h"

namespace lunk {
	class TileEngine {
	public:
		TileEngine(Renderer *renderer, TileMap *tileMap, Texture *tileAtlas) :
				renderer(renderer),
				tileMap(tileMap),
				atlas(tileAtlas) { }

		void drawTile(double x, double y, int type) {
			const Rect2 tileSourceRect = tileMap->getTileRect(type);

			renderer->drawTexture(atlas, Vec2(x, y), &tileSourceRect);
		}

		void drawTile(Vec2 v, int type) {
			drawTile(v.x, v.y, type);
		}

	private:
		Renderer *renderer;
		TileMap *tileMap;
		Texture *atlas;
	};
}