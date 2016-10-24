#include "lib/game.h"
#include "lib/rm.h"
#include "lib/sr.h"
#include "lib/wtile.h"

SpriteRenderer *Renderer;

Game::Game(GLuint width, GLuint height)
	: State(GAME_ACTIVE), Keys(), Width(width), Height(height)
{
}

Game::~Game()
{
	delete Renderer;
}


void Game::Init()
{

	ResourceManager::LoadShader("data/shaders/sprite.vs", "data/shaders/sprite.frag", nullptr, "sprite");
	glm::mat4 projection = glm::ortho(0.0f, static_cast<GLfloat>(this->Width), static_cast<GLfloat>(this->Height), 0.0f, -1.0f, 1.0f);
	ResourceManager::GetShader("sprite").Use().SetInteger("image", 0);
	ResourceManager::GetShader("sprite").SetMatrix4("projection", projection);
	//Renderer = new SpriteRenderer(ResourceManager::GetShader("sprite"));
	Shader shh;
	shh = ResourceManager::GetShader("sprite");
	Renderer = new SpriteRenderer(shh);

	ResourceManager::LoadTexture("data/tex/maps/fields/worldfields.png", GL_TRUE, "worldfields");
	worldfieldstex = ResourceManager::GetTexture("worldfields");
	ResourceManager::LoadTexture("data/tex/maps/plains/worldplains.png", GL_TRUE, "worldplains");
	worldplainstex = ResourceManager::GetTexture("worldplains");
	ResourceManager::LoadTexture("data/tex/maps/crags/worldcrags.png", GL_TRUE, "worldcrags");
	worldcragstex = ResourceManager::GetTexture("worldcrags");
	ResourceManager::LoadTexture("data/tex/maps/beach/worldbeach.png", GL_TRUE, "worldbeach");
	worldbeachtex = ResourceManager::GetTexture("worldbeach");
	ResourceManager::LoadTexture("data/tex/maps/imp/worldimp.png", GL_TRUE, "worldimp");
	worldimptex = ResourceManager::GetTexture("worldimp");
	ResourceManager::LoadTexture("data/tex/maps/sea/worldsea.png", GL_TRUE, "worldsea");
	worldseatex = ResourceManager::GetTexture("worldsea");
	ResourceManager::LoadTexture("data/tex/maps/sea/worldcoast.png", GL_TRUE, "worldcoast");
	worldcoasttex = ResourceManager::GetTexture("worldcoast");

	for(int i=0; i<25; i++){
		x[i] = rand()%(Width/16);
		y[i] = rand()%(Height/16);
	}
}


void Game::Update(GLfloat dt)
{
}

void Game::ProcessInput(GLfloat dt)
{
}

void Game::Render()
{
	//World w(90, 60);
	//w.Draw(*Renderer);
	//Texture2D tex;
	//tex = ResourceManager::GetTexture("worldfields");
	
	
    WTile w(glm::vec2(x[1],y[1]), worldfieldstex, 2);
	w.Draw(*Renderer);
	//Renderer->DrawSprite(tex, glm::vec2(100, 500), glm::vec2(16, 16), 0.0f, glm::vec3(1.0f, 1.0f, 1.0f));
	//Renderer->DrawSprite(ResourceManager::GetTexture("fields1"), glm::vec2(200, 200), glm::vec2(300, 400), 45.0f, glm::vec3(0.0f, 1.0f, 0.0f));
}
