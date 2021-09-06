#include "Taiga.h"

Object obj;
Renderer renderer;

void draw();
void setup();

int main(int argc, char** args) {
	Engine engine;
	engine.init("Conifer v0.1 (Taiga Engine v0.92)", 1028, 720, draw, setup);
	return 0;
}

void setup() {
	obj.Make(-0.5, -0.5, 1.0, 1.0);
}

void draw() {
	renderer.Draw(obj.m_Shader, obj.m_VAOID, obj.m_IBOID);
}

