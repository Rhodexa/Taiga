#pragma once

/*
	Includes all dependencies needed to use Taiga Engine in your project.
*/

#include <string>
#include <iostream>
#include "glstuff.h"
#include "Engine.h"
#include "Object.h"
#include "Textures.h"
#include "Shader.h"
#include "TaigaCore.h"
#include "vsglassert.h"
#include "glm.hpp"
#include "gtc/matrix_transform.hpp"

#define MAKE_TAIGA_APP(x) Taiga* getApplication() { x* taiga = new x; return taiga; }