#pragma once

#include "ShaderProgram.cpp"
#include "Window.cpp"

class Engine
{
	private:
		ShaderProgram shaders;
		glm::mat4 view;

	public:
		GLFWwindow* window;
		float deltaTime;
		float lastFrame;

		uint32_t VAO;

		void run();

		void initGL();

		void mainLoop();
		void commands();
		void processInput(GLFWwindow* window);

		void cleanup();
};