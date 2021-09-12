#include "Shader.h"
#include "vsglassert.h"

Shader::Shader() : m_ShaderID(0) {}
Shader::~Shader() {}

Shader::Programs Shader::loadShaderFile(const std::string& file_path) {
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
		glGetProgramiv(program, GL_LINK_STATUS, &linked);
		if (linked == GL_FALSE) {
			int length = 0;
			glGetProgramiv(program, GL_INFO_LOG_LENGTH, &length);
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
	m_ShaderID = linkShaders(program_id, vs, fs);
	return m_ShaderID;
}


// We can make this run way faster
// Here's a ToDo list for ya: We need a system that can look up for uniforms during compilation/parsing and store them.
// Then, once the Shader gets compiled, it should ask OpenGL the location of all those uniforms and store a relation array of Names -> Locations
// This way, we can just acces uniforms instead of asking OGL where they ara every frame. It's not so complicated, Good luck! 
int Shader::GetUniformLocation(const std::string& name) {
	int location = glGetUniformLocation(m_ShaderID, name.c_str());
	if (location == -1)
		std::cout << "Taiga - Shader Manager Warning!: Uniform " << name << " doesn't exist" << std::endl;
	return location;
}

void Shader::SetUniform1i(const std::string& name, int v0) {
	glUniform1i(GetUniformLocation(name), v0);
}

void Shader::SetUniform1f(const std::string& name, float v0) {
	glUniform1f(GetUniformLocation(name), v0);
}

void Shader::SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3) {
	glUniform4f(GetUniformLocation(name), v0, v1, v2, v3);
}

void Shader::SetUniformMat4f(const std::string& name, const glm::mat4& mat) {
	glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, &mat[0][0]);
}
