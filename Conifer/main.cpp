#include "Taiga.h"

Object obj;
Renderer renderer;
Texture text("res/conifer4.png");

void draw();
void setup();

int GetUniformLocation(const std::string& name, unsigned int m_RendererID) {	
	int location = glGetUniformLocation(m_RendererID, name.c_str());
	std::cout << location << std::endl;
	if (location == -1)
		std::cout << "Taiga - Shader Manager Warning!: Uniform " << name << " doesn't exist" << std::endl;
	return location;
}

void SetUniform1i(const std::string& name, int v0, unsigned int m_RendererID) {
	glUniform1i(GetUniformLocation(name, m_RendererID), v0);
}

void SetUniform1f(const std::string& name, float v0) {
	glUniform1f(GetUniformLocation(name, 0), v0);
}

void SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3) {
	glUniform4f(GetUniformLocation(name, 0), v0, v1, v2, v3);
}

int main(int argc, char** args) {
	Engine engine;
	engine.init("Conifer v0.1 (Taiga Engine v0.92)", 1028, 720, draw, setup);	
	return 0;
}

void setup() {
	obj.Make(-0.35, -0.475, 0.7, 0.95);
	text.make();
	text.bind(0);
	SetUniform1i("u_Texture", 0, obj.m_Shader);
}

void draw() {
	renderer.Draw(obj.m_Shader, obj.m_VAOID, obj.m_IBOID);
}

