#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Debug.h"

namespace GLAD
{
	inline void initGLAD()
	{
		if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
			Debug::Error("Failed to initialize GLAD!");
	}
}