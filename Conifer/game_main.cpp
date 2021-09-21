#include "Taiga.h"

class Game : public Taiga {
public:
	Game() {std::cout << "Conifer Created!\n";}
	~Game() {}
	void draw() override;
	void setup() override;

public:
	double x = 0, y = 0;
	int w = 0, h = 0;
	Renderer renderer;
	Shader shader;
	Camera camera;
	Sprite sprite;
	Texture sprite_sheet;
	glm::vec3 cam_pos = { 0.0, 0.0, -500.0 };

	float inter_frame = 0;
};
MAKE_TAIGA_APP(Game);


// This runs once
void Game::setup() {
	sprite_sheet.make("res/luma/luma.png");
	sprite_sheet.bind(0); // bind the sprite sheet in the GPU's texture slot 0

	sprite.make(sprite_sheet, 2, 3, 100, 100);

	shader.make("../Shaders/basic_shader.shader");	
	
	camera.setPosition(cam_pos);
}

// This runs at 60FPS (I guess, we gotta test that)
void Game::draw() {
		// REALLY BASIC input capture
		glfwGetCursorPos(m_Window, &x, &y);
		glfwGetWindowSize(m_Window, &w, &h);
		x = x - w / 2;
		y = -y + h / 2;
		if (glfwGetKey(m_Window, GLFW_KEY_W)) cam_pos.z += 10;
		if (glfwGetKey(m_Window, GLFW_KEY_S)) cam_pos.z -= 10;
		if (glfwGetKey(m_Window, GLFW_KEY_A)) cam_pos.x -= 10;
		if (glfwGetKey(m_Window, GLFW_KEY_D)) cam_pos.x += 10;
		if (glfwGetKey(m_Window, GLFW_KEY_Q)) cam_pos.y -= 10;
		if (glfwGetKey(m_Window, GLFW_KEY_E)) cam_pos.y += 10;
		camera.setPosition(cam_pos);

		glm::vec3 cam_dir = { float(x), float(y), -cam_pos.z};
		camera.setOrientation(cam_dir);

		glm::mat4 proj = glm::perspectiveLH(1.2, double(w)/double(h), -1.0, 1.0);
		glm::mat4 view = camera.view_matrix;

		// pass matrices to our shader
		shader.setUniformMat3f("UV_MAP", sprite.sprite_matrix);		
		shader.setUniformMat4f("MVP", proj * view);

		inter_frame += 0.2;
		sprite.setFrame(((unsigned int) inter_frame) % 6);

	
	renderer.draw(sprite, shader);
}





