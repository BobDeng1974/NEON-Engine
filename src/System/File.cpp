#include "File.h"

string File::getLine(std::ifstream& stream) {
	std::size_t size = 100;
	string output(size);

	uint32_t index = 0;
	while(true) {
		char c;
		stream.get(c);

		if(c == '\0' || c == '\n')
			return output;
		else {
			if(output.length <= index) {
				size += 50;
				output.realloc(size);
			}

			output[index] = c;
		}
		index++;
	}

	return nullptr;
}

string File::getWord(std::ifstream& stream, char splitter) {
	
}