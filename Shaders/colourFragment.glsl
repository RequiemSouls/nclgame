#version 150 core

in Vertex {
	vec4 colour;
} IN;

out vec4 glColor;

void main(void) {
	glColor = IN.colour;
}