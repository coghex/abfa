#include "lib/game.h"
#include "lib/rm.h"
#include "lib/sr.h"

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
}

void Game::Update(GLfloat dt)
{
}

void Game::ProcessInput(GLfloat dt)
{
}

void Game::Render()
{
 	Texture2D tex;
	tex = ResourceManager::GetTexture("worldfields");
	Renderer->DrawSprite(tex, glm::vec2(16, 16), glm::vec2(16, 16), 0.0f, glm::vec3(1.0f, 1.0f, 1.0f));
	//Renderer->DrawSprite(ResourceManager::GetTexture("fields1"), glm::vec2(200, 200), glm::vec2(300, 400), 45.0f, glm::vec3(0.0f, 1.0f, 0.0f));
}
