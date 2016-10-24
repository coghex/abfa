#include "world.h"
#include <fstream>
#include <sstream>

World::World() : mapw(90), maph(60) {}
World::World(int w, int h) : mapw(w), maph(h) {}

void World::Draw(SpriteRenderer &renderer) {
	for(Zone &zone : this->Zones) {
		zone.Draw(renderer);
	}
}

void World::init(int w, int h) {
	Zone z(1, 15, glm::vec2(10,10));
	this->Zones.push_back(z);
}
