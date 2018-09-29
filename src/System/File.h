#pragma once
#include <fstream>

#include "string.h"

namespace File
{
	// Gets one word from stream
	string getWord(std::ifstream& stream);
	string getWord(std::ifstream& stream, char splitter);
	// Gets whole line from stream
	string getLine(std::ifstream& stream);
}