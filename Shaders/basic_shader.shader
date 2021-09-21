!shadertype vertex
#version 330 core

layout(location = 0) in vec4 vertexPos;
layout(location = 1) in vec2 tex_coord;

uniform mat4 MVP;
uniform mat3 UV_MAP;

out vec3 v_tex_coord;
void main() {
	gl_Position = MVP * vertexPos;
	v_tex_coord = UV_MAP * vec3(tex_coord.x, tex_coord.y, 1.0);
}




!shadertype fragment
#version 330 core

uniform sampler2D u_Texture;

in vec3 v_tex_coord;

out vec4 color;
void main() {
	color = texture(u_Texture, v_tex_coord.xy);
	//color = vec4(0.9, 0.16, 0.3, 1.0);
}