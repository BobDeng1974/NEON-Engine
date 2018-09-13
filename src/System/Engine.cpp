#define WIDTH 720
#define HEIGHT 480

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Engine.h"
#include "Debug.h"

void Engine::run()
{
	initWindow();
	initGLAD();

	glViewport(0, 0, WIDTH, HEIGHT);

	mainLoop();
	cleanup();
}

inline void Engine::initWindow()
{
	window.initWindow(WIDTH, HEIGHT);
	glfwSetFramebufferSizeCallback(window.window, this->framebuffer_size_callback);
}

inline void Engine::initGLAD()
{
	if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		Debug::Error("Failed to initialize GLAD!");
	std::cout << "pepa";
}

void Engine::framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void Engine::proccessInput(Window* window)
{
	if(glfwGetKey(window->window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window->window, GLFW_TRUE);
}

void Engine::mainLoop()
{
	while(!window.shouldClose())
	{
		proccessInput(&window);
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window.window);
		glfwPollEvents();
	}
}

void Engine::cleanup()
{
	glfwTerminate();
}