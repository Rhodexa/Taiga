#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "glstuff.h"



class Shader {
public:
	Shader();
	~Shader();

	struct ShaderTypes {
		std::string vertex_shader;
		std::string fragment_shader;
	} source;

	ShaderTypes loadShaderFile(const std::string& file_path);
	int compileShader(GLenum type, const std::string& _file);
	int createBasicShader(const std::string& vert_path, const std::string& frag_path);
	int linkShaders(const unsigned int& program, const unsigned int& vert_shader_id, const unsigned int& frag_shader_id);
};

