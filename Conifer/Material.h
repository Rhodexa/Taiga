#pragma once
#include "Shader.h"

class Material {
private:
	Shader shader;
	unsigned int m_TextureID;

public:
	Material();
	~Material();
};

