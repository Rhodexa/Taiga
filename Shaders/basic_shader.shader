#shadertype vertex
#version 330 core						 
layout(location = 0) in vec4 vertexPos;
layout(location = 1) in vec4 vertColor;
out vec4 col;
void main() {							 
	gl_Position = vertexPos;
	col = vertexPos;
}



#shadertype fragment
#version 330 core
in vec4 col;
out vec4 color;						
void main() {						
	//color = vec4(0.9, 0.16, 0.3, 1.0);
	color = vec4(col.r + 0.5, col.g + 0.5, 0.5, 1.0);
}