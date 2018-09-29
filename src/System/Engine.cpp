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
	shaders = ShaderProgram();
	shaders.addShader(GL_VERTEX_SHADER, ContentPipeline::LoadShader("/home/martin/Projects/NEONEngine/assets/Shaders/defaultVertexShader.glsl"));
	shaders.addShader(GL_FRAGMENT_SHADER, ContentPipeline::LoadShader("/home/martin/Projects/NEONEngine/assets/Shaders/defaultFragmentShader.glsl"));

	Debug::Message("Linking Program!");
	shaders.linkProgram();
	Mesh mesh = ContentPipeline::loadOBJ("/home/martin/Desktop/monu10.obj");
	indiceCount = mesh.indiceCount;

	for(uint32_t i = 0; i < mesh.verticeCount; i++) { 
		std::cout << mesh.vertices[i] << "|";
	} 
	std::cout << std::endl;
	for(uint32_t i = 0; i < mesh.indiceCount; i++) { 
		std::cout << mesh.indices[i] << "|";
	}

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
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * (mesh.verticeCount + mesh.normalCount), nullptr, GL_DYNAMIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(uint32_t) * mesh.indiceCount, mesh.indices, GL_DYNAMIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	uint32_t location = glGetUniformLocation(shaders.program, "projection");

	glm::mat4 proj = glm::mat4(1.0f);
	proj = glm::perspective(glm::radians(45.0f), (float)720/480, 0.1f, 100.0f);
	proj[3][3] = 1.0f;
	glm::mat4 model = glm::mat4(1.0f);
	model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));
	model[3][3] = 1.0f;

	glm::mat4 view = glm::mat4(1.0f);
	view = glm::translate(view, glm::vec3(0.0f, 0.0f, 3.0f));
	view[3][3] = 1.0f;

	std::cout << std::endl << "Projection : " << std::endl;
	for(uint32_t x = 0; x < 4; x++) {
		for(uint32_t y = 0; y < 4; y++) {
			std::cout << proj[y][x] << "|";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl << "Model : " << std::endl;
	for(uint32_t x = 0; x < 4; x++) {
		for(uint32_t y = 0; y < 4; y++) {
			std::cout << model[y][x] << "|";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl << "View : " << std::endl;
	for(uint32_t x = 0; x < 4; x++) {
		for(uint32_t y = 0; y < 4; y++) {
			std::cout << view[y][x] << "|";
		}
		std::cout << std::endl;
	}

	std::cout << glGetUniformLocation(shaders.program, "projection");
	std::cout << glGetUniformLocation(shaders.program, "model");
	std::cout << glGetUniformLocation(shaders.program, "view");
	glUniformMatrix4fv(glGetUniformLocation(shaders.program, "projection"), 1, GL_FALSE, &proj[0][0]);
	glUniformMatrix4fv(glGetUniformLocation(shaders.program, "model"), 1, GL_FALSE, &model[0][0]);
	glUniformMatrix4fv(glGetUniformLocation(shaders.program, "view"), 1, GL_FALSE, &view[0][0]);
}

// Loop of the game engine
// =======================
void Engine::mainLoop()
{
	while(!glfwWindowShouldClose(window))
	{
		processInput(window);
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		shaders.useProgram();

		glm::mat4 proj = glm::mat4(1.0f);
		proj = glm::perspective(glm::radians(45.0f), (float)720/480, 0.1f, 100.0f);
		proj[3][3] = 1.0f;
		glm::mat4 model = glm::mat4(1.0f);
		//model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));
		model[3][3] = 1.0f;

		glm::mat4 view = glm::mat4(1.0f);
		view = glm::translate(view, glm::vec3(0.0f, 0.0f, -300.0f));
		view[3][3] = 1.0f;
		glUniformMatrix4fv(glGetUniformLocation(shaders.program, "projection"), 1, GL_FALSE, &proj[0][0]);
		glUniformMatrix4fv(glGetUniformLocation(shaders.program, "model"), 1, GL_FALSE, &model[0][0]);
		glUniformMatrix4fv(glGetUniformLocation(shaders.program, "view"), 1, GL_FALSE, &view[0][0]);

		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, indiceCount, GL_UNSIGNED_INT, 0);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}

void Engine::commands() {

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