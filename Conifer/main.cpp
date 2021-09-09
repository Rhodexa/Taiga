#include "Taiga.h"

Object obj;
Renderer renderer;
Texture tex("res/conifer4.png");

void draw();
void setup();

int main(int argc, char** args) {
	Engine engine;
	engine.init("Conifer v0.1 (Taiga Engine v0.92)", 1028, 720, draw, setup);	
	return 0;
}

void setup() {
	obj.Make(-0.35, -0.475, 0.7, 0.95);
	tex.make();
	tex.bind(0);
	obj.program.SetUniform1i("u_Texture", 0, obj.m_Shader);
}

void draw() {
	renderer.Draw(obj.m_Shader, obj.m_VAOID, obj.m_IBOID);
}