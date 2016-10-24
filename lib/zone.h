#ifndef ZONE_H
#define ZONE_H
#include <vector>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include "lib/rm.h"
#include "lib/sr.h"
#include "lib/worldtile.h"


class Zone
{
	public:
		std::vector<WorldTile> Tiles;
		int size, type;
		glm::vec2 position;

		Zone();
		Zone(int t, int s, glm::vec2 pos);
		void Draw(SpriteRenderer &renderer);
	private:
		void init(int t, int s, glm::vec2 pos);
};

#endif
