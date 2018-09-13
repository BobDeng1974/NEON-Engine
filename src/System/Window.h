#pragma once

class Window
{
	public:
		GLFWwindow* window;

		void initWindow(uint32_t width, uint32_t height);
		inline bool shouldClose();

		~Window();
};