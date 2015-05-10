#pragma once

#include <vector>
#include <SDL.h>

namespace lunk {
	class Rect2;

	class TileMap {
	public:
		TileMap(int);

		virtual ~TileMap();

		void setTileRect(int type, int x, int y, int w, int h);

		const Rect2 getTileRect(int tileType);

	private:
		std::vector<Rect2> tiles;
	};
}