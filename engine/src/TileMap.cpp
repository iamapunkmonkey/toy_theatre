#include "TileMap.h"

#include "Rect2.h"

namespace lunk {
	TileMap::TileMap(int count) : tiles(std::vector<Rect2>(count)) {
	}

	TileMap::~TileMap() {
	}

	void TileMap::setTileRect(int type, int x, int y, int w, int h) {
		tiles[type] = Rect2{x, y, w, h};
	}

	const Rect2 TileMap::getTileRect(int tileType) {
		return tiles[tileType];
	}
}