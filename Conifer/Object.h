#pragma once
#include "glstuff.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexAttribs.h"
#include "Textures.h"
#include "Shader.h"

class Object {
public:
	//float _x = 0, _y = 0, _w = 0, _h = 0;
	unsigned int m_VBOID = 0;
	unsigned int m_IBOID = 0;
	unsigned int m_ShaderID = 0;
	VertexBuffer vbo;
	IndexBuffer ibo;
	VertexLayout vaa;
	Shader shader;
	Texture tex;
	unsigned int indices[6] = { 0, 1, 2, 2, 3, 0 };

public:

	Object();
	~Object();

	void make(float x, float y, float w, float h);
};

