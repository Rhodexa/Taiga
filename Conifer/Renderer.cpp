#include "Renderer.h"


void Renderer::draw(VertexBuffer &vbo, IndexBuffer& ibo, VertexLayout &vaa, unsigned int shader) const {
	glUseProgram(shader);
	glBindBuffer(GL_ARRAY_BUFFER, vbo.ID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo.ID);
	vaa.bind(vbo);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
}
