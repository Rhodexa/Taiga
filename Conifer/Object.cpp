#include "Object.h"

Object::Object() {}
Object::~Object() {}

void Object::make(float x, float y, float w, float h) {

	float vertices[16] = {
	//  X pos, Y pos, U tex coord, V tex coord
		x,     y,	  0.0f, 0.0f,
		x + w, y,	  1.0f, 0.0f,
		x + w, y + h, 1.0f, 1.0f,
		x,     y + h, 0.0f, 1.0f
	};

	unsigned int indices[6] = { 0, 1, 2, 2, 3, 0 };
	
	vbo.make(vertices, 16); // Load the vertex buffer to the GPU
	vaa.append(2);				// vertex components layout: Vertex pos X, Y at location 0
	vaa.append(2);				// vertex components layout: Texture Coordinates U, V at location 1
	vaa.build(vbo);				// load the vertex components to the GPU
	ibo.make(indices, 6);	// Load the index buffer to the GPU
}