#pragma once
#include "glstuff.h"
#include "Shader.h"

class Object {
public:
	float _x = 0, _y = 0, _w = 0, _h = 0;
	unsigned int m_VBOID = 0;
	unsigned int m_IBOID = 0;
	unsigned int m_VAOID = 0;
	unsigned int m_Shader = 0;

public:
	Object();
	~Object();

	void Make(float x, float y, float w, float h);
};

