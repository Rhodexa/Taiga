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
	Material material;
	Camera camera;
	Object obj;
	double x = 0, y = 0;
	int w = 0, h = 0;
	glm::vec3 cam_pos = { 0.0, 0.0, -500.0 };
};

// Tell Taiga this is the main frame we're gonna be working on.
// Taiga will handle everything else for us. (Hopefully)
// The reason being that the App entry point is inside TaigaCore, weird, i know.
// You can always define TGA_LEMME_DO_IT_MY_WAY before including Taiga.h to tell Taiga you want to make your own main() function
MAKE_TAIGA_APP(Conifer);


// This runs once
void Conifer::setup() {
	obj.make(-100, -100, 200, 200);	
	material.make("../Shaders/basic_shader.shader", "res/conifer_logo.png");
	
	camera.setPosition(cam_pos);
}



// Conifer inherits Taiga. setup() and draw() are empty in there, but we have overriden them in Conifer.
// This runs at 60FPS (I guess, we gotta test that)
void Conifer::draw() {
	// This is just a quick app that will show the new Coifer logo following the cursor.
		// get cursor
		glfwGetCursorPos(m_Window, &x, &y);
		// get window size
		glfwGetWindowSize(m_Window, &w, &h);
		x = x - w / 2;
		y = -y + h / 2;


		// BASIC input capture
		if (glfwGetKey(m_Window, GLFW_KEY_W)) {
			cam_pos.z += 10;
			camera.setPosition(cam_pos);
		};
		if (glfwGetKey(m_Window, GLFW_KEY_S)) {
			cam_pos.z -= 10;
			camera.setPosition(cam_pos);
		};
		if (glfwGetKey(m_Window, GLFW_KEY_A)) {
			cam_pos.x -= 10;
			camera.setPosition(cam_pos);
		};
		if (glfwGetKey(m_Window, GLFW_KEY_D)) {
			cam_pos.x += 10;
			camera.setPosition(cam_pos);
		};
		if (glfwGetKey(m_Window, GLFW_KEY_Q)) {
			cam_pos.y -= 10;
			camera.setPosition(cam_pos);
		};
		if (glfwGetKey(m_Window, GLFW_KEY_E)) {
			cam_pos.y += 10;
			camera.setPosition(cam_pos);
		};







		glm::vec3 cam_dir = { float(x), float(y), -cam_pos.z};
		//camera.setTarget(cam_dir);
		camera.setOrientation(cam_dir);

		glm::mat4 proj = glm::perspectiveLH(1.2, double(w)/double(h), -1.0, 1.0);
		glm::mat4 view = camera.view_matrix;

		glm::mat4 model = {
			1.0, 0.0, 0.0, 0.0, 
			0.0, 1.0, 0.0, 0.0,
			0.0, 0.0, 1.0, 0.0,
			0.0, 0.0, 0.0, 1.0
		};

		// pass the matrix to our shader
		material.shader.SetUniformMat4f("MVP", proj * view * model);

	renderer.draw(obj,  material);
}





