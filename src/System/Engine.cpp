#define WIDTH 720
#define HEIGHT 480

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Engine.h"
#include "Debug.h"
#include "Mesh.cpp"
#include "ShaderProgram.cpp"
#include "ContentPipeline.cpp"

uint32_t indiceCount = 0;
uint32_t VAO = 0;

void Engine::run()
{
	Debug::Message("Initializing Window!");
	initWindow();
	Debug::Message("Initializing GLAD!");
	initGLAD();

	Debug::Message("Initializing OpenGL!");
	initGL();

	Debug::Message("Viewport Created!");
	glViewport(0, 0, WIDTH, HEIGHT);

	Debug::Message("Main loop entered!");
	mainLoop();
	cleanup();
}

void Engine::initWindow()
{
	window.initWindow(WIDTH, HEIGHT);
	glfwSetFramebufferSizeCallback(window.window, this->framebuffer_size_callback);
}

void Engine::initGLAD()
{
	if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		Debug::Error("Failed to initialize GLAD!");
	std::cout << "pepa";
}

void Engine::initGL()
{
	ShaderProgram shaders;
	shaders.addShader(GL_VERTEX_SHADER, ContentPipeline::LoadOBJ(__ASSETS__ + "/Shaders/defaultVertexShader.glsl"));

	float vertices[] = {
         0.5f,  0.5f, 0.0f,  // top right
         0.5f, -0.5f, 0.0f,  // bottom right
        -0.5f, -0.5f, 0.0f,  // bottom left
        -0.5f,  0.5f, 0.0f   // top left 
    };
    unsigned int indices[] = {  // note that we start from 0!
        0, 1, 3,  // first Triangle
        1, 2, 3   // second Triangle
    };

	uint32_t VBO, EBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &EBO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_DYNAMIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_DYNAMIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
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

		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, indiceCount, GL_UNSIGNED_INT, 0);

		glfwSwapBuffers(window.window);
		glfwPollEvents();
	}
}

void Engine::cleanup()
{
	glfwTerminate();
}