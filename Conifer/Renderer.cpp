#include "Renderer.h"
#include "Shader.h"

void Renderer::Draw(const unsigned int& shader, const unsigned int& _VAOID, const unsigned int& _IBOID) const {
	glUseProgram(shader);
	glBindVertexArray(_VAOID);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);		
}
