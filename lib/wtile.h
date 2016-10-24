#ifndef WTILE_H
#define WTILE_H

#include <GL/glew.h>
#include <glm/glm.hpp>
#include "lib/texture.h"
#include "lib/sr.h"

class WTile
{
    public:
        glm::vec2 position;
        int type;
        Texture2D sprite;
        
        WTile();
        WTile(glm::vec2 pos, Texture2D spr, int t);
        virtual void Draw(SpriteRenderer &renderer);
};
#endif
        
