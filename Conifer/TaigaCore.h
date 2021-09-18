#pragma once
#include <iostream>
#include <string>
#include "glstuff.h"
#include "Engine.h"
#include "Object.h"
#include "Textures.h"
#include "Shader.h"

class Taiga : public Engine {
private:

public:
	const char* windowName;

public:
	Taiga();
	Taiga(const char*);
	~Taiga();
	virtual void setup();
	virtual void draw();
};
