#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "Debug.h"
#include "Window.h"

void Window::init(uint32_t width, uint32_t height)
{
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(width, height, "NEON Engine", nullptr, nullptr);
	if(window == NULL)
	{
		Debug::Error("Couldn't create GLFW Window!");
		glfwTerminate();
	}

	glfwMakeContextCurrent(window);
}

inline bool Window::shouldClose() { return glfwWindowShouldClose(window); }

Window::~Window()
{
	glfwTerminate();
}