#include "zone.h"
#include <fstream>
#include <sstream>

Zone::Zone() : type(0), size(10), position(0,0) {}
Zone::Zone(int t, int s, glm::vec2 pos) : type(t), size(s), position(pos) {}

void Zone::Draw(SpriteRenderer &renderer) {
	for(WorldTile &tile : this->Tiles) {
		tile.Draw(renderer);
	}
}

void Zone::init(int t, int s, glm::vec2 pos){
	WorldTile w(pos, t);
	this->Tiles.push_back(w);
}
