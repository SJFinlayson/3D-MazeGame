#version 330 core

in vec3 fragmentColor;
// Ouput data
out vec3 color;

void main() {
	
	color = fragmentColor;
	//color = vec3(0.0, 0.0, 1.0);
}