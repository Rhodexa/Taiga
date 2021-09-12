#pragma once
#include "glstuff.h"
#include "Shader.h"
#include "VertexBuffer.h"
#include "VertexAttribs.h"
#include "IndexBuffer.h"

class Renderer {
public:
	void draw(VertexBuffer& vbo, IndexBuffer& ibo, VertexLayout& vaa, unsigned int shader) const;
};

