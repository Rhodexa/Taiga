#shadertype vertex
#version 330 core	

layout(location = 0) in vec4 vertexPos;
layout(location = 1) in vec2 u_textCoord;
out vec2 v_textCoord;
void main() {							 
	gl_Position = vertexPos;
	v_textCoord = u_textCoord;
}



#shadertype fragment
#version 330 core

in vec2 v_textCoord;
uniform sampler2D u_Texture;
out vec4 color;
void main() {
	vec4 texColor = texture(u_Texture, v_textCoord);
	color = texColor;
	//color = vec4(v_textCoord.x, v_textCoord.y, 1.0, 1.0);
	//color = vec4(0.9, 0.16, 0.3, 1.0);
}