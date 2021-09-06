#include "Engine.h"
#include "logitext.h"

Object obj;
Renderer renderer;

Engine::Engine() {
	m_Window = nullptr;
	//m_Surface = nullptr;
	m_State = State::PLAY;
}

Engine::~Engine() {
	//SDL_DestroyWindow(m_Window);
	//SDL_Quit();
	glfwTerminate();
}

void Engine::init(const char* title, int w, int h) {
	std::cout << "Conifer v0.1 running over Taiga Engine v0.92" << std::endl;
	
	/*
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) logpush::end("ERROR: SDL failed to start");

	m_Window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);
		if (!m_Window) logpush::end("ERROR: SDL window creation failed");

	m_Surface = SDL_GetWindowSurface(m_Window);
		if (!m_Surface) logpush::end("ERROR: For some reason SDL failed to get the window's surface");

	SDL_GLContext gl_context = SDL_GL_CreateContext(m_Window);
		if (!gl_context) logpush::end("Failed to make a GL context");
	*/

	if (!glfwInit()) logpush::end("ERROR: GLFW failed to start");
	
	m_Window = glfwCreateWindow(w, h, title, NULL, NULL);
		if (!m_Window) logpush::end("ERROR: GLFW window creation failed");
	
	glfwMakeContextCurrent(m_Window);

	// END OF SDL -> GLFW PORT

	glewExperimental = true;
		if(glewInit() != GLEW_OK) logpush::end("Oof... GLEW failed this time");

	std::cout << "Cool!, everything seems to be working." << std::endl;

	//SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	
	obj.Make(-0.35f, -0.5f, 0.7f, 1.0f);

	glfwSwapInterval(1);

	mainLoop();
}

void Engine::mainLoop() {
	//while (m_State != State::EXIT) {
	while (!glfwWindowShouldClose(m_Window)){
		//glfwSetFramebufferSizeCallback(m_Window, windowResize);
		pollEvents();
		draw();
	}
}

void Engine::pollEvents() {
	/* SDL Stuff
	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		switch (e.type) {
		case SDL_QUIT:
			m_State = State::EXIT;
			break;

		case SDL_WINDOWEVENT:
			if(e.window.event == SDL_WINDOWEVENT_RESIZED) resizeViewport(e);
			break;

		case SDL_MOUSEMOTION:
			mouseX = e.motion.x;
			mouseY = e.motion.y;
			break;
		}
	}*/
	glfwPollEvents();
}

void Engine::draw() {
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	renderer.Draw(obj.m_Shader, obj.m_VAOID, obj.m_IBOID);

	int width, height;
	glfwGetWindowSize(m_Window, &width, &height);
	windowResize(m_Window, width, height);

	//SDL_GL_SwapWindow(m_Window);
	glfwSwapBuffers(m_Window);
}

/*
void Engine::resizeViewport(SDL_Event& e) {
	glViewport(0, 0, e.window.data1, e.window.data2);
}
*/

// We need to manage to implement continous repaint while risizing.
// Some say we should put the drawing into its own thread. I agree, but no idea how to do that just yet.
void Engine::windowResize(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}