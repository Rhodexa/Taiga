#include "Textures.h"
#include "stb_image.h"
#include <iostream>


Texture::Texture(const std::string& path) : m_Path(path), m_TBOID(0), m_TexBuffer(nullptr), m_Width(0), m_Height(0), m_BPP(0) {
	
}

Texture::~Texture() {
	if (m_TexBuffer) stbi_image_free(m_TexBuffer);
	glDeleteTextures(1, &m_TBOID);
}

void Texture::make() {
	stbi_set_flip_vertically_on_load(1);
	m_TexBuffer = stbi_load(m_Path.c_str(), &m_Width, &m_Height, &m_BPP, 4);
	std::cout << m_Width << " " << m_Height << "\n";

	glGenTextures(1, &m_TBOID);
	std::cout << m_TBOID << "\n";
	if (!m_TBOID)
		std::cout << "Failed to gen Texture" << "\n";
	glBindTexture(GL_TEXTURE_2D, m_TBOID);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_Width, m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_TexBuffer);
	glBindTexture(GL_TEXTURE_2D, 0);

	if (m_TexBuffer)
		stbi_image_free(m_TexBuffer);
}

void Texture::bind(unsigned int slot = 0) {
	glActiveTexture(GL_TEXTURE0 + slot);
	glBindTexture(GL_TEXTURE_2D, m_TBOID);
}

void Texture::unbind() {
	glBindTexture(GL_TEXTURE_2D, 0);
}