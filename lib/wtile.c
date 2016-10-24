#include "wtile.h"

WTile::WTile() : position(0,0), type(0), sprite() {}
WTile::WTile(glm::vec2 pos, Texture2D spr, int t) : position(pos), sprite(spr), type(t) {}

void WTile::Draw(SpriteRenderer &renderer) {
    position.x *= 4;
    position.y *= 4;
    renderer.DrawSprite(this->sprite, this->position, glm::vec2(4,4), 0.0f, glm::vec3(0.8f, 0.8f, 0.8f));
}