#pragma once

#include "Window.cpp"

class Engine
{
	private:
		Window window;

	public:
		void run();

		void initWindow();
		void initGLAD();

		void initGL();

		void proccessInput(Window* window);

		static void framebuffer_size_callback(GLFWwindow* window, int width, int height);

		void mainLoop();

		void cleanup();
};