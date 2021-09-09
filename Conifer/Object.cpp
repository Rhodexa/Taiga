#include "Object.h"
#include "VertexBuffer.h"

Object::Object() {}

Object::~Object() {
	if (!m_IBOID) glDeleteBuffers(1, &m_IBOID);
	if (!m_VAOID) glDeleteBuffers(1, &m_VAOID);
}

void Object::Make(float x, float y, float w, float h) {
	float vertices[] = {
		x,	   y, 	  0.0f, 0.0f,
		x + w, y,	  1.0f, 0.0f,
		x + w, y + h, 1.0f, 1.0f,
		x,	   y + h, 0.0f, 1.0f
	};

	unsigned int indices[] = {
		0, 1, 2,
		2, 3, 0
	};

	if(!m_VAOID) glGenVertexArrays(1, &m_VAOID);
	glBindVertexArray(m_VAOID);

	VertexBuffer buffer;
	buffer.make(vertices);


	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), 0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (const void*) (2 * sizeof(float)));
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	if (!m_IBOID) glGenBuffers(1, &m_IBOID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IBOID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(unsigned int), indices, GL_STATIC_DRAW);

	Shader::Programs source = program.loadShaderFile("../Shaders/basic_shader.shader");
	m_Shader = program.createBasicShader(source.vertex_shader, source.fragment_shader);
}