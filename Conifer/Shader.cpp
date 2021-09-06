#include "Shader.h"

Shader::Shader() {}
Shader::~Shader() {}

Shader::ShaderTypes Shader::loadShaderFile(const std::string& file_path) {
	std::ifstream file(file_path);
	std::string line;
	std::stringstream source[2];

	enum class SourceType {
		NONE = -1,
		VERTEX,
		FRAGMENT
	} source_type;

	unsigned int line_n = 0;
	while (getline(file, line)) {
		if (line.find("#shadertype") != std::string::npos) {
			if (line.find("vertex") != std::string::npos)
				source_type = SourceType::VERTEX;
			else if (line.find("fragment") != std::string::npos)
				source_type = SourceType::FRAGMENT;
			else
				std::cout << "WARNING: Shader file \"" << file_path << "\" line " << line_n+1 << std::endl << " \"" << line << "\" undefined shader type." << std::endl;
		}
		else 
			source[(int) source_type] << line << "\n";
		line_n++;
	}

	return { source[0].str(), source[1].str() };
}

int Shader::compileShader(GLenum type, const std::string& _file) {
	GLuint id = glCreateShader(type);
	if (!id) {
		std::cout << "Failed to create Shader" << std::endl;
		return -1;
	}
	const char* file = _file.c_str();
	glShaderSource(id, 1, &file, nullptr);
	glCompileShader(id);

	// Error Handling
		int compiled;
		glGetShaderiv(id, GL_COMPILE_STATUS, &compiled);
		if (compiled == GL_FALSE) {
			int length = 0;
			glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
			char* err = (char*) alloca(length * sizeof(char));
			glGetShaderInfoLog(id, length, &length, err);

			std::cout << std::endl;
			std::cout << (type == GL_VERTEX_SHADER ? "OpenGL COMPILATION ERROR: Vertex Shader" : "OpenGL COMPILATION ERROR: Fragment Shader") << std::endl;
			std::cout << std::endl;
			std::cout << err << std::endl;

			glDeleteShader(id);
			std::cout << "Failed to compile Shader" << std::endl;
			return -1;
		}

	return id;
}

int Shader::linkShaders(const unsigned int& program, const unsigned int& vert_shader_id, const unsigned int& frag_shader_id) {
	glAttachShader(program, vert_shader_id);
	glAttachShader(program, frag_shader_id);
	glLinkProgram(program);
	glValidateProgram(program);

	// Error Handling
		int linked;
		glGetShaderiv(program, GL_LINK_STATUS, &linked);
		if (linked == GL_FALSE) {
			int length = 0;
			glGetShaderiv(program, GL_INFO_LOG_LENGTH, &length);
			char* err = (char*) alloca(length * sizeof(char));
			glGetShaderInfoLog(program, length, &length, err);

			std::cout << "OpenGL LINKING ERROR" << std::endl;
			std::cout << std::endl;
			std::cout << err << std::endl;

			glDeleteShader(program);
			glDeleteProgram(program);
			glDeleteShader(vert_shader_id);
			glDeleteShader(frag_shader_id);
			std::cout << "Failed to link Shader" << std::endl;
			return -1;
		}
	
	// Delete intermediates after compilation
	glDeleteShader(vert_shader_id);
	glDeleteShader(frag_shader_id);

	// Delete Shaders from GPU's memory
	glDetachShader(program, vert_shader_id);
	glDetachShader(program, frag_shader_id);

	return program;
}

int Shader::createBasicShader(const std::string& vert_path, const std::string& frag_path) {
	unsigned int program_id = glCreateProgram();
	unsigned int vs = compileShader(GL_VERTEX_SHADER, vert_path);
	unsigned int fs = compileShader(GL_FRAGMENT_SHADER, frag_path);
	unsigned int cp = linkShaders(program_id, vs, fs);
	return cp;
}