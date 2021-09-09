#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "glstuff.h"

class Shader {
private:
	unsigned int m_ShaderID;

public:
	Shader();
	~Shader();

	struct Programs {
		std::string vertex_shader;
		std::string fragment_shader;
	} source;

	Programs loadShaderFile(const std::string& file_path);
	int compileShader(GLenum type, const std::string& _file);
	int createBasicShader(const std::string& vert_path, const std::string& frag_path);
	int linkShaders(const unsigned int& program, const unsigned int& vert_shader_id, const unsigned int& frag_shader_id);

	int  GetUniformLocation(const std::string& name, unsigned int m_RendererID);
	void SetUniform1i(const std::string& name, int v0, unsigned int m_RendererID);
	void SetUniform1f(const std::string& name, float v0);
	void SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3);
};

