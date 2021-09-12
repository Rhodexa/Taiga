#pragma once
#include "glstuff.h"

class VertexBuffer {
private:

public:
	VertexBuffer();
	~VertexBuffer();

	unsigned int ID;

	unsigned int make(const float* buffer, unsigned int count);
	void bind() const ;
	void unbind() const;
};


