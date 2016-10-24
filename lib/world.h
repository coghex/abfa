#ifndef WORLD_H
#define WORLD_H
#include <vector>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include "lib/rm.h"
#include "lib/sr.h"
#include "lib/zone.h"

class World {
	public:
		std::vector<Zone> Zones;
		int nzones;
		int mapw;
		int maph;

		World();
		World(int w, int h);
		void Draw(SpriteRenderer &renderer);
	private:
		void init(int w, int h);
};

#endif
