#include "File.h"

string File::getLine(std::ifstream& stream) {
	std::size_t size = 100;
	string output(size);

	while(true) {
		char c;
		stream.get(c);

		if(c == '\0' || c == '\n') {
			return output;
		}

		else {
			if(output.length <= i) {
				
			}
		}
	}
}