#pragma once
#include <string>
#include <iostream>
#include "glstuff.h"
#include "Object.h"
#include "Renderer.h"

enum class State {
	PLAY,
	EXIT
};

class Engine {
private:
	GLFWwindow* m_Window;
	//SDL_Surface* m_Surface;
	State m_State;

	void draw();

public:
	float mouseX = 0;
	float mouseY = 0;

public:
	Engine();
	~Engine();

	void init(const char*, int, int);
	void pollEvents();
	void mainLoop();
	void windowResize(GLFWwindow* window, int width, int height);
	//void resizeViewport(SDL_Event& e);
};

