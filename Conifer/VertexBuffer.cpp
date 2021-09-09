#include "VertexBuffer.h"
#include "glstuff.h"

VertexBuffer::VertexBuffer() : m_VBOID(0) {}
VertexBuffer::~VertexBuffer() {}

unsigned int VertexBuffer::make(const void* buffer) {
	if (!m_VBOID) glGenBuffers(1, &m_VBOID);
	glBindBuffer(GL_ARRAY_BUFFER, m_VBOID);
	glBufferData(GL_ARRAY_BUFFER, 4 * 4 * sizeof(float), buffer, GL_STATIC_DRAW);

	return m_VBOID;
}

void VertexBuffer::bind() {
	glBindBuffer(GL_ARRAY_BUFFER, m_VBOID);
}

void VertexBuffer::unbind() {
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

VertexLayout::VertexLayout() : m_Stride(0) {}
VertexLayout::~VertexLayout() {}

template<typename T> void VertexLayout::Push(unsigned int count) {
	static_assert(false);
}

template<> void VertexLayout::Push<float>(unsigned int count) {
	m_Component.push_back({ GL_FLOAT, count, GL_FALSE });
	m_Stride += VertexComponent::sizeOf(GL_FLOAT) * count;
}

template<> void VertexLayout::Push<unsigned int>(unsigned int count) {
	m_Component.push_back({ GL_UNSIGNED_INT, count, GL_FALSE });
	m_Stride += VertexComponent::sizeOf(GL_UNSIGNED_INT) * count;
}