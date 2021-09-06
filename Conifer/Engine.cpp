#include "Engine.h"


Engine::Engine() {
	m_Window = nullptr;
}

Engine::~Engine() {
	glfwTerminate();
}

void Engine::init(const char* title, int w, int h, void(*draw_func)(), void(*setup_func)()) {
	drawFunc = draw_func;
	setupFunc = setup_func;
	std::cout << "Conifer v0.1 running over Taiga Engine v0.92" << std::endl;
	if (!glfwInit()) {
		std::cout << "ERROR: GLFW failed to start" << std::endl;
		glfwTerminate();
	}
	
	m_Window = glfwCreateWindow(w, h, title, NULL, NULL);
	if (!m_Window) {
		std::cout << "ERROR: GLFW window creation failed" << std::endl;
		glfwTerminate();
	}
	
	glfwMakeContextCurrent(m_Window);

	glewExperimental = true;
	if (glewInit() != GLEW_OK) {
		std::cout << "ERROR: Oof... GLEW failed this time" << std::endl;
		glfwTerminate();
	}

	std::cout << "Cool!, everything seems to be working." << std::endl;
	
	glfwSwapInterval(1);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	setupFunc();
	mainLoop();
}

void Engine::mainLoop() {
	while (!glfwWindowShouldClose(m_Window)){
		pollEvents();
		draw();
	}
}

void Engine::pollEvents() {
	glfwPollEvents();
}

extern void drawLoop();

void Engine::draw() {
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	drawFunc();

	int width, height;
	glfwGetWindowSize(m_Window, &width, &height);
	windowResize(m_Window, width, height);
	glfwSwapBuffers(m_Window);
}

// We need to find a way to implement continous repaint while risizing.
// Some say we should put the drawing into its own thread. I agree, but no idea how to do that just yet.
void Engine::windowResize(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}