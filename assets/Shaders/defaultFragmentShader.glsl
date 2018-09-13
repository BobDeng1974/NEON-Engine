#version 440 core
layout(position = 0) in vec3 vertices;

void main()
{
	gl_Position = vertices;
}