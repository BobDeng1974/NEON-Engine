#include "File.h"

char* File::readLine(std::ifstream* stream, uint32_t* length)
{
	char* str = new char[100];

	for(int i = 0; ; i++)
		stream->read(str + i, 1);

	return str;
}