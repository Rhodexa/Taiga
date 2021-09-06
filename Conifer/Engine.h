#pragma once
#include <string>
#include <iostream>
#include "glstuff.h"
#include "Object.h"
#include "Renderer.h"

//enum class State {
//	PLAY,
//	EXIT
//};

class Engine {
private:
	GLFWwindow* m_Window;
	//State m_State;
	void draw();
	void(*drawFunc)();
	void(*setupFunc)();

public:
	float mouseX = 0;
	float mouseY = 0;

public:
	Engine();
	~Engine();

	void init(const char*, int, int, void(*draw_func)(), void(*setup_func)());
	void pollEvents();
	void mainLoop();
	void windowResize(GLFWwindow* window, int width, int height);
};

