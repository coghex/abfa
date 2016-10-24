#ifndef WORLDTILE_H
#define WORLDTILE_H
#include <vector>
#include <GL/glew.h>
#include <glm/glm.hpp>

#include "lib/go.h"
#include "lib/sr.h"
#include "lib/rm.h"

class WorldTile
{
	public:
		GameObject tile;
		glm::vec2 position;
		int type;
		GLboolean passable;

		WorldTile();
		WorldTile(glm::vec2 pos, int t);
		void Draw(SpriteRenderer &renderer);
		GLboolean Passable();
	private:
		void init(glm::vec2 pos, int t);
};
#endif
