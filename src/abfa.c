#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "lib/game.h"
#include "lib/rm.h"

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);

const GLuint SCREEN_WIDTH = 1440;
const GLuint SCREEN_HEIGHT = 960;
Game ABFA(SCREEN_WIDTH, SCREEN_HEIGHT);
int main(int argc, char *argv[]){
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	GLFWwindow* window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "A Bridge Far Away...", nullptr, nullptr);
	glfwMakeContextCurrent(window);
	glewExperimental = GL_TRUE;
	glewInit();
	glGetError();
	glfwSetKeyCallback(window, key_callback);
	glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	glEnable(GL_CULL_FACE);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	ABFA.Init();
	GLfloat deltaTime = 0.0f;
	GLfloat lastFrame = 0.0f;
	ABFA.State = GAME_ACTIVE;

	while(!glfwWindowShouldClose(window)){
		GLfloat currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;
		glfwPollEvents();
		ABFA.ProcessInput(deltaTime);
		ABFA.Update(deltaTime);
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		ABFA.Render();
		glfwSwapBuffers(window);
	}
	ResourceManager::Clear();
	glfwTerminate();
	return 0;
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode){
	if(key==GLFW_KEY_ESCAPE && action == GLFW_PRESS){
		glfwSetWindowShouldClose(window, GL_TRUE);
	}
	if(key>=0 && key < 1024){
		if(action==GLFW_PRESS){
			ABFA.Keys[key] = GL_TRUE;
		}
		else if(action==GLFW_RELEASE){
			ABFA.Keys[key] = GL_FALSE;
		}
	}
}
