#include <iostream>
#include <fstream>

#include "string.cpp"

namespace File
{
	string readLine(std::ifstream& stream);
	string readWord(std::ifstream& stream);

	void skipLine(std::ifstream* stream);
}