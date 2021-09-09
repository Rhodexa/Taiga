#pragma once
#include "glstuff.h"
#include "VertexBuffer.h"
#include <vector>



class VertexArray {
private:
	unsigned int m_RendererID;

public:
	VertexArray();
	~VertexArray();

	void AddBuffer(const VertexBuffer& vb, const VertexLayout& layout);
	void Bind() const;
	void Unbind() const;
};