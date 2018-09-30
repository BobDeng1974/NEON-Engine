#define WIDTH 720
#define HEIGHT 480

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Engine.h"
#include "Debug.h"
#include "Mesh.cpp"
#include "ContentPipeline.cpp"
#include "Material.cpp"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

uint32_t indiceCount = 0;

Material material(glm::vec3(0.2f, 0.2f, 0.2f), glm::vec3(0.5f, 0.5f, 0.5f), glm::vec3(1.0f, 1.0f, 1.0f));

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
	glEnable(GL_DEPTH_TEST);
	view = glm::mat4(1.0f);
	view = glm::translate(view, glm::vec3(0.0f, 0.0f, -300.0f));
	glm::vec3 viewPos(0.0f, 0.0f, -300.0f);
	view[3][3] = 1.0f;

	shaders = ShaderProgram();
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
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * (mesh.verticeCount), mesh.vertices, GL_DYNAMIC_DRAW);

	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(float) * mesh.verticeCount, mesh.vertices);
	glBufferSubData(GL_ARRAY_BUFFER, mesh.verticeCount * sizeof(float), sizeof(float) * mesh.normalCount, mesh.normals);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(uint32_t) * mesh.indiceCount, mesh.indices, GL_DYNAMIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)(mesh.verticeCount * sizeof(float)));
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}

// Loop of the game engine
// =======================
void Engine::mainLoop()
{
	while(!glfwWindowShouldClose(window))
	{
		float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

		processInput(window);
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		shaders.useProgram();

		glm::mat4 proj = glm::mat4(1.0f);
		proj = glm::perspective(glm::radians(45.0f), (float)720/480, 0.1f, 100.0f);
		proj[3][3] = 1.0f;
		glm::mat4 model = glm::mat4(1.0f);
		model[3][3] = 1.0f;

		glUniformMatrix4fv(glGetUniformLocation(shaders.program, "projection"), 1, GL_FALSE, &proj[0][0]);
		glUniformMatrix4fv(glGetUniformLocation(shaders.program, "model"), 1, GL_FALSE, &model[0][0]);
		glUniformMatrix4fv(glGetUniformLocation(shaders.program, "view"), 1, GL_FALSE, &view[0][0]);
		glUniform3fv(glGetUniformLocation(shaders.program, "viewPos"), 1, &glm::inverse(view)[0][3]);
		glm::vec3 lightPos(1.0f, 1.0f, 1.0f);  
		glUniform3fv(glGetUniformLocation(shaders.program, "lightPos"), 1, &lightPos[0]);

		material.uniform(shaders.program);

		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, indiceCount, GL_UNSIGNED_INT, 0);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}

void Engine::commands() {
	std::cout << std::endl << "Type in commands : " << std::endl;
	while(glfwWindowShouldClose(window)) {
		string command;
		std::cin >> command;

		if(command.startsWith("load")) {
			std::cin >> command;
			
		}
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
void Engine::processInput(GLFWwindow *window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

	if(glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) {
		view = glm::translate(view, glm::vec3(0.0f, -50.0f * deltaTime, 0.0f));
	}

	if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
		view = glm::translate(view, glm::vec3(0.0f, 0.0f, 50.0f * deltaTime));
	}
	if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
		view = glm::translate(view, glm::vec3(0.0f, 0.0f, -50.0f * deltaTime));
	}
	if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
		view = glm::translate(view, glm::vec3(50.0f * deltaTime, 0.0f, 0.0f));
	}
	if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
		view = glm::translate(view, glm::vec3(-50.0f * deltaTime, 0.0f, 0.0f));
	}
}

// Resize the framebuffer size
// ===========================
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}