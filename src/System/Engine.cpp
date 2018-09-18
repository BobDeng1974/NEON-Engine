#define WIDTH 720
#define HEIGHT 480

#define __ASSETS__ "/home/martin/Projects/NEON Engine/assets"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Engine.h"
#include "Debug.h"
#include "Mesh.cpp"
#include "GLAD.h"
#include "ContentPipeline.cpp"

uint32_t indiceCount = 0;
uint32_t VAO = 0;

void Engine::run()
{
	Debug::Message("Initializing OpenGL");
	initGL();

	Debug::Message("Viewport created!");
	glViewport(0, 0, WIDTH, HEIGHT);

	Debug::Message("Main Loop Entered!");
	mainLoop();
	cleanup();
}

void Engine::initGL()
{
	shaders.addShader(GL_VERTEX_SHADER, ContentPipeline::LoadShader("/home/martin/Projects/NEONEngine/assets/Shaders/defaultVertexShader.glsl"));
	shaders.addShader(GL_FRAGMENT_SHADER, ContentPipeline::LoadShader("/home/martin/Projects/NEONEngine/assets/Shaders/defaultFragmentShader.glsl"));

	Debug::Message("Linking Program!");
	shaders.linkProgram();

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
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_DYNAMIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_DYNAMIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Engine::mainLoop()
{
	while(!glfwWindowShouldClose(window))
	{
		//proccessInput(&window);
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		shaders.useProgram();

		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}

void Engine::cleanup()
{
	glfwTerminate();
}