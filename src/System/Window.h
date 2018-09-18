#pragma once

struct Window
{
	public:
		GLFWwindow* window;

		void init(uint32_t width, uint32_t height);
		inline bool shouldClose();

		~Window();
};