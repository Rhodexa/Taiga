#pragma once
#include "glstuff.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexAttribs.h"
#include "Textures.h"
#include "Shader.h"

class Object {
public:
	VertexBuffer vbo;
	IndexBuffer ibo;
	VertexLayout vaa;

public:

	Object();
	~Object();

	void make(float x, float y, float w, float h);
};

