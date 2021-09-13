#pragma once
#include "glstuff.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexAttribs.h"
#include "Textures.h"
#include "Shader.h"

class Object {
public:
	unsigned int m_VBOID = 0;
	unsigned int m_IBOID = 0;
	unsigned int m_ShaderID = 0;
	VertexBuffer vbo;
	IndexBuffer ibo;
	VertexLayout vaa;
	Shader shader;
	Texture tex;

public:

	Object();
	~Object();

	void make(float x, float y, float w, float h);
};

