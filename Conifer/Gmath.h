#pragma once
/*
	Taiga's GL Algebra

	I see you screaming WHY DIDNT YOU JUST USE GLM OR SOMETHING, YOU LAWYS MAKING YOUR LIFE HARDER!!!!!!!!!!
	i dont care, i hate black boxes.

	But we can use GLM if you don't want to reinvent the wheel


	yeaaaah... we're gonna go with GLM, scrap this.
*/


namespace gmath{
	typedef struct mat4 { float mat[16]; } mat4;
	typedef struct vec4 { float vec[4]; } vec4;
}

gmath::vec4 operator*(gmath::vec4& mat1, gmath::mat4& mat2);

namespace gmath {
	mat4 orthogonal(float w, float h);
	mat4 scale(float x, float y, float z);
	mat4 translate(float x, float y, float z);
}