#include "Object.h"

Object::Object() {}

Object::~Object() {
	if (!m_VBOID) glDeleteBuffers(1, &m_VBOID);
	if (!m_IBOID) glDeleteBuffers(1, &m_IBOID);
	if (!m_VAOID) glDeleteBuffers(1, &m_VAOID);
}

void Object::Make(float x, float y, float w, float h) {
	float vertices[] = {
		x,	   y, 	  1.0, 1.0, 1.0,
		x + w, y,	  1.0, 1.0, 1.0,
		x + w, y + h, 1.0, 1.0, 1.0,
		x,	   y + h, 1.0, 1.0, 1.0
	};

	unsigned int indices[] = {
		0, 1, 2,
		2, 3, 0
	};

	if(!m_VAOID) glGenVertexArrays(1, &m_VAOID);
	glBindVertexArray(m_VAOID);

	if (!m_VBOID) glGenBuffers(1, &m_VBOID);
	glBindBuffer(GL_ARRAY_BUFFER, m_VBOID);
	glBufferData(GL_ARRAY_BUFFER, 4 * 5 * sizeof(float), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), 0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), 0);
	glEnableVertexAttribArray(0);

	if (!m_IBOID) glGenBuffers(1, &m_IBOID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IBOID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(unsigned int), indices, GL_STATIC_DRAW);

	Shader program;
	Shader::ShaderTypes source = program.loadShaderFile("../Shaders/basic_shader.shader");
	m_Shader = program.createBasicShader(source.vertex_shader, source.fragment_shader);
}