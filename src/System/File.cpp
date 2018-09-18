#include "File.h"

string File::readLine(std::ifstream& stream)
{
	string result;

	char* charBuffer = new char[10];
	uint32_t bufferIndex = 0;

	while(true)
	{
		char c;
		stream.get(c);

		if(c != '\n' || c != '\0')
		{
			if(bufferIndex == 10)
			{
				bufferIndex = 0;

			}

			charBuffer[bufferIndex] = c;
			bufferIndex++;
		}
	}
}