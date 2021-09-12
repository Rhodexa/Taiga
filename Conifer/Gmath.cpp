#include "Gmath.h"

gmath::vec4 operator*(gmath::vec4& vec1, gmath::mat4& mat2) {
	return gmath::vec4{
		vec1.vec[0] * mat2.mat[0] + vec1.vec[0] * mat2.mat[4] + vec1.vec[0] * mat2.mat[8]  + vec1.vec[0] * mat2.mat[12],
		vec1.vec[1] * mat2.mat[1] + vec1.vec[1] * mat2.mat[5] + vec1.vec[1] * mat2.mat[9]  + vec1.vec[1] * mat2.mat[13],
		vec1.vec[2] * mat2.mat[2] + vec1.vec[2] * mat2.mat[6] + vec1.vec[2] * mat2.mat[10] + vec1.vec[2] * mat2.mat[14],
		vec1.vec[3] * mat2.mat[3] + vec1.vec[3] * mat2.mat[7] + vec1.vec[3] * mat2.mat[11] + vec1.vec[3] * mat2.mat[15]
	};
}

namespace gmath {
	mat4 orthogonal(float w, float h) {
		return {
			1.0f / w, 0.0f,     0.0f, 0.0f,
			0.0f,	  1.0f / h, 0.0f, 0.0f,
			0.0f,	  0.0f,     1.0f, 0.0f,
			0.0f,	  0.0f,     0.0f, 1.0f,
		};
	}

	mat4 scale(float x, float y, float z) {
		return {
			x,   0.0, 0.0, 0.0,
			0.0, x,   0.0, 0.0,
			0.0, 0.0, z,   0.0,
			0.0, 0.0, 0.0, 1.0,
		};
	}

	mat4 translate(float x, float y, float z) {
		return {
			1.0, 0.0, 0.0, x,
			0.0, 1.0, 0.0, y,
			0.0, 0.0, 1.0, z,
			0.0, 0.0, 0.0, 1.0,
		};
	}
}