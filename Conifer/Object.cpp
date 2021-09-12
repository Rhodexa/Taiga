#include "Object.h"

Object::Object() {}
Object::~Object() {}

void Object::make(float x, float y, float w, float h) {
	float vertices[16] = {
		x,     y,	  0.0f, 0.0f,
		x + w, y,	  1.0f, 0.0f,
		x + w, y + h, 1.0f, 1.0f,
		x,     y + h, 0.0f, 1.0f
	};
	
	vbo.make(vertices, 16);
	vaa.append(2);
	vaa.append(2);
	vaa.build(vbo);
	ibo.make(indices, 6);

	Shader::Programs source = shader.loadShaderFile("../Shaders/basic_shader.shader");
	m_ShaderID = shader.createBasicShader(source.vertex_shader, source.fragment_shader);

	tex.make("res/conifer_logo.png");
	tex.bind(0);
		
	glUseProgram(m_ShaderID);
	shader.SetUniform1i("u_Texture", 0);
}