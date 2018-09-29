#define WIDTH 720
#define HEIGHT 480

#define __ASSETS__ "/home/martin/Projects/NEON Engine/assets"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Engine.h"
#include "Debug.h"
#include "Mesh.cpp"
#include "ContentPipeline.cpp"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

uint32_t indiceCount = 0;

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
	Mesh mesh = ContentPipeline::loadOBJ("/home/martin/Desktop/cube.obj");
	indiceCount = mesh.indiceCount;

	uint32_t VBO, EBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * mesh.verticeCount, mesh.vertices, GL_DYNAMIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(uint32_t) * mesh.indiceCount, mesh.indices, GL_DYNAMIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	uint32_t location = glGetUniformLocation(shaders.program, "projection");

	glm::mat4 proj = glm::perspective(glm::radians(45.0f), (float)WIDTH/(float)HEIGHT, 0.1f, 100.0f);
	glm::mat4 model;
	model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));

	glm::mat4 view;
	view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));

	shaders.uniformMatrix4x4(proj, glGetUniformLocation(shaders.program, "projection"));
	shaders.uniformMatrix4x4(model, glGetUniformLocation(shaders.program, "model"));
	shaders.uniformMatrix4x4(view, glGetUniformLocation(shaders.program, "view"));
}

// Loop of the game engine
// =======================
void Engine::mainLoop()
{
	while(!glfwWindowShouldClose(window))
	{
		processInput(window);
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_TEST);
		shaders.useProgram();

		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, indiceCount, GL_UNSIGNED_INT, 0);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}

// Cleans up after the engine
// ==========================
void Engine::cleanup()
{
	glfwTerminate();
}

// Processess input from user
// ==========================
void processInput(GLFWwindow *window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

// Resize the framebuffer size
// ===========================
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}