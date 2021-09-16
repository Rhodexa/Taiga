#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include "glstuff.h"
#include "glm.hpp"

class Shader {
private:
	unsigned int m_ShaderID;
	std::vector<std::string>	m_uniforms_types;
	std::vector<std::string>	m_uniforms_names;
	std::vector<int>			m_uniforms_locat;
	std::map<std::string, int>	m_uniforms_map;

public:
	Shader();
	~Shader();

	struct Programs {
		std::string vertex_shader;
		std::string fragment_shader;
	} source;

	Programs loadShaderFile(const std::string& file_path);
	int compileShader(GLenum type, const std::string& _file);
	int linkShaders(const unsigned int& program, const unsigned int& vert_shader_id, const unsigned int& frag_shader_id);
	void loadUniformLocations();

	void make(const std::string& file_path);
	void bind();
	void unbind();

	int  GetUniformLocation(const std::string& name) const;
	int  GetUniformLocation(const unsigned int index) const;
	void SetUniform1i(const std::string& name, int v0);
	void SetUniform1f(const std::string& name, float v0);
	void SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3);
	void SetUniformMat4f(const std::string& name, const glm::mat4&);
};

