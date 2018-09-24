#define TEST

//#include <glad/glad.h>
//#include <GLFW/glfw3.h>

#include <iostream>

#include "string.cpp"

// Main method containing all the code that needs to be defined globally
// =====================================================================
#ifdef TEST
int main()
{
    std::cout << "hello";
    string str = "dneska je pekne pocasi!";
    uint32_t count = 0;
    std::cout << str.data();
    string** strings = str.split(' ', count);
    //std::cout << strings[0]->data();
}
#else
int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Handle Mac compatibility
    #ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    #endif

    // Creates GLFW window
    // ===================
    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "NEON Engine", NULL, NULL);
    if (window == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // Loads GLAD
    // ==========
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // Initialize the engine
	Engine engine;
	engine.window = window; // Sets the window pointer
	engine.run(); // Runs the engine
}
#endif