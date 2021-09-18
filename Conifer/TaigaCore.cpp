#include "TaigaCore.h"

extern Taiga* getApplication();

Taiga::Taiga() : windowName("Taiga Engine v0.9.34.120921") {std::cout << "Taiga Core Created!\n";}
Taiga::Taiga(const char* window_name) : windowName(window_name) {std::cout << "Taiga Core Created!\n";}
Taiga::~Taiga() {}

#ifndef TGA_LEMME_DO_IT_MY_WAY
int main(int argc, char** args) {
	Taiga* taiga = getApplication();

	taiga->init(taiga->windowName, 1024, 720);
	taiga->setup();
	while (!glfwWindowShouldClose(taiga->m_Window)) {
		taiga->clear();
		taiga->draw();
		taiga->update();
	}
	delete taiga;
	glfwTerminate();
	return 0;
}
#endif

void Taiga::setup() {}
void Taiga::draw() {}


