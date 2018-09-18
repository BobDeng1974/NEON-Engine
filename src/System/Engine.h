#pragma once

#include "ShaderProgram.cpp"
#include "Window.cpp"

class Engine
{
	private:
		ShaderProgram shaders;

	public:
		GLFWwindow* window;

		void run();

		void initGL();

		void mainLoop();

		void cleanup();
};