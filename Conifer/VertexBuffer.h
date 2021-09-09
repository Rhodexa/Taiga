#pragma once
#include <vector>
#include "glstuff.h"

struct VertexComponent {
	unsigned int type;
	unsigned int count;
	unsigned char normalized;

	static unsigned int sizeOf(unsigned int type) {
		switch (type) {
			case GL_FLOAT:			return 4;
			case GL_UNSIGNED_INT:	return 4;
			case GL_UNSIGNED_BYTE:	return 1;
		}
		return 0;
	}
};

class VertexBuffer {
private:
	unsigned int m_VBOID;

public:
	VertexBuffer();
	~VertexBuffer();

	unsigned int make(const void* buffer);
	void bind();
	void unbind();
};

class VertexLayout {
private:
	std::vector<VertexComponent> m_Component;
	unsigned int m_Stride;

public:
	VertexLayout();
	~VertexLayout();

	template<typename T> void Push(unsigned int count);
	template<> void Push<float>(unsigned int count);
	template<> void Push<unsigned int>(unsigned int count);
};
