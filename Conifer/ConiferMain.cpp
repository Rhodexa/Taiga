#include "Taiga.h"
//#include "Gmath.h" We don't use our custom Algebra lib anymore, we switched to GLM now, cause... let's be honest, it's far more advanced than ours. 
// But we ARE gonna make our own sooner or later!

class Conifer : public Taiga {
public:
	//Conifer() : Taiga("Custom window name!") { std::cout << "Conifer Created!\n"; }
	Conifer() {std::cout << "Conifer Created!\n";}
	~Conifer() {}
	void draw();
	void setup();

// custom app variables go here
public:
	Renderer renderer;
	Object obj;	
};

// Tell Taiga this is the main frame we're gonna be working on.
// Taiga will handle everything else for us. (Hopefully)
// The reason being that the App entry point is inside TaigaCore, weird, i know.
// You can always define TGA_LEMME_DO_IT_MY_WAY before including Taiga.h to tell Taiga you want to make your own main() function
MAKE_TAIGA_APP(Conifer);


// This runs once
void Conifer::setup() {
	obj.make(-100, -100, 200, 200);
	
}


// Conifer inherits Taiga. setup() and draw() are empty in Taiga, but we have overriden them in Conifer.
// This runs at 60FPS (I guess, we gotta solve that)
void Conifer::draw() {
	// I think it would be nice if this functions actaully takes an Object class as an argument, plus a material. 
	// Altough Materials could be an intrinsict property of Objects themselves.
	//	Like renderer.draw(obj); or renrer.draw(obj, material);
	// An Object is a collection of buffers, it takes vertex data and material data, then puts everything into a single class -> Object. 
	// But for now, an Object is a rectangle. xd

	int w, h;
	glfwGetWindowSize(m_Window, &w, &h);
	glm::mat4 proj = glm::ortho((double)-w / 2, (double)w / 2, (double)-h / 2, (double)h / 2, -1.0, 1.0);
	obj.shader.SetUniformMat4f("proj", proj);

	renderer.draw(obj.vbo, obj.ibo, obj.vaa, obj.m_ShaderID);

	// SUPER basic error capturing... just for testing
	// we could delete this, it's actually helpless... xD
	GLenum err = glGetError();
	if (err != GL_NO_ERROR)
		std::cout << err << std::endl;
}





