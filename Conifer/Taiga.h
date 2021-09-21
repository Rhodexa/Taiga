#pragma once

/*
	Includes all dependencies needed to use Taiga Engine in your project.
*/

#include <string>
#include <iostream>
#include "vsglassert.h"

#include "glstuff.h"
#include "gmath.h"
#include "Engine.h"
#include "Object.h"
#include "Textures.h"
#include "Shader.h"
#include "Camera.h"
#include "Sprite.h"

#include "TaigaCore.h"

#define MAKE_TAIGA_APP(x) Taiga* getApplication() { x* taiga = new x; return taiga; }
