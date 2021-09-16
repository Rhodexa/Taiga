#pragma once
#include <iostream>
#include "gmath.h"

class Camera {
private:	

public:
	glm::mat4 view_matrix;

public:
	Camera();
	~Camera();

	void set(glm::vec3 position, glm::vec3 target);
};

