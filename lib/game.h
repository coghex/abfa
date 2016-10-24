#ifndef GAME_H
#define GAME_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include "lib/sr.h"

enum GameState {
	GAME_ACTIVE,
	GAME_MENU,
	GAME_END
};

class Game
{
	public:
		GameState State;
		GLboolean Keys[1024];
		GLuint Width, Height;
		Texture2D worldfieldstex, worldplainstex, worldcragstex, worldbeachtex, worldseatex, worldcoasttex, worldimptex;
		int x[25], y[25];
		
		Game(GLuint width, GLuint height);
		~Game();
		void Init();
		void ProcessInput(GLfloat dt);
		void Update(GLfloat dt);
		void Render();
};

#endif
