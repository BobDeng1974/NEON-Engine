#pragma once

#include <iostream>
#include <cstdint>

#define FOREGROUND_RESET "\033[0m\n"

#define FOREGROUND_RED "\033[1;31m"
#define FOREGROUND_GREEN "\033[1;32m"
#define FOREGROUND_YELLOW "\033[1;33m"
#define FOREGROUND_BLUE "\033[1;34m"
#define FOREGROUND_MAGENTA "\033[1;35m"
#define FOREGROUND_CYAN "\033[1;36m"

namespace Debug
{
	inline void Error(char* message) {
		#ifdef DEBUG
		std::cout << FOREGROUND_RED << __TIME__ << " [ERROR]: " << message << FOREGROUND_RESET;
		#endif
	}

	inline void Warning(char* message) {
		#ifdef DEBUG
		std::cout << FOREGROUND_YELLOW << __TIME__ << " [WARNING]: " << message << FOREGROUND_RESET;
		#endif
	}

	inline void Message(char* message) {
		#ifdef DEBUG
		std::cout << FOREGROUND_BLUE << __TIME__ << " [MESSAGE]: " << message << FOREGROUND_RESET;
		#endif
	}

	inline void List(const char* name, char** items, uint32_t count)
	{
		#ifdef DEBUG
		std::cout << FOREGROUND_BLUE << "[" << name << "]\n" << FOREGROUND_MAGENTA;
		
		for(uint32_t i = 0; i < count; i++)
			std::cout << i + 1 << ". " << items[i] << std::endl;

		std::cout << FOREGROUND_RESET;
		#endif
	}
}