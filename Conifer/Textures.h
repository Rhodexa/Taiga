#pragma once
#include <string>
#include "glstuff.h"


class Texture {
private:
	std::string m_Path;
	unsigned int m_TBOID;
	unsigned char* m_TexBuffer;
	int m_Width, m_Height, m_BPP;
	
public:
	Texture(const std::string& path);
	~Texture();
	void make();
	void bind(unsigned int slot);
	void unbind();
};

