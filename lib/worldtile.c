#include "lib/worldtile.h"
#include "lib/go.h"


WorldTile::WorldTile() : position(0,0), type(0){}

WorldTile::WorldTile(glm::vec2 pos, int t) : position(pos), type(t) {}

void WorldTile::Draw(SpriteRenderer &renderer){
	tile.Draw(renderer);
}

GLboolean WorldTile::Passable(){
	return passable;
}

void WorldTile::init(glm::vec2 pos, int t){
	position = pos;
	glm::vec2 size(16, 16);
	type = t;

	if(type==0){
		GameObject obj(pos, size, ResourceManager::GetTexture("worldimp"), glm::vec3(0.8f, 0.8f, 0.8f));
		passable=GL_FALSE;
	}
	if(type==1){
		GameObject obj(pos, size, ResourceManager::GetTexture("worldplains"), glm::vec3(0.8f, 0.8f, 0.8f));
		passable=GL_TRUE;
	}
	if(type==2){
		GameObject obj(pos, size, ResourceManager::GetTexture("worldfields"), glm::vec3(0.8f, 0.8f, 0.8f));
		passable=GL_TRUE;
	}
	if(type==3){
		GameObject obj(pos, size, ResourceManager::GetTexture("worldcrags"), glm::vec3(0.8f, 0.8f, 0.8f));
		passable=GL_TRUE;
	}
	if(type==4){
		GameObject obj(pos, size, ResourceManager::GetTexture("worldbeach"), glm::vec3(0.8f, 0.8f, 0.8f));
		passable=GL_TRUE;
	}
	if(type==5){
		GameObject obj(pos, size, ResourceManager::GetTexture("worldsea"), glm::vec3(0.8f, 0.8f, 0.8f));
		passable=GL_FALSE;
	}
	if(type==6){
		GameObject obj(pos, size, ResourceManager::GetTexture("worldcoast"), glm::vec3(0.8f, 0.8f, 0.8f));
		passable=GL_FALSE;
	}

}
