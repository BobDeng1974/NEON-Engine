#include "string.hpp"

#pragma region Constructor
// Constructors
// ============
string::string() :
characters(new char[16]), length(0), size(16) {

}

string::string(size_t size) :
characters(new char[size]), length(0), size(size) {

}

string::string(char str[]) :
characters(str), length(sizeof(str)), size(sizeof(str)) {
	
}

string::string(char* str, const uint32_t size) :
characters(str), length(size), size(size) {

}
#pragma endregion

bool string::startsWith(string* token) {
	for(uint32_t i = 0; i < token->length; i++) {
		if(token->get(i) != this->get(i)) {
			return false;
		}
	}

	return true;
}

string* string::split(char splitter, uint32_t& splitCount) {
	for(uint32_t i = 0; i < this->length; i++) {
		if(this->get(i) == splitter) {
			splitCount++;
		}
	}
	uint32_t resultIndex = 0;
	uint32_t splitIndex = 0;

	

	for(uint32_t i = 0; i < this->length; i++) {
		if(this->get(i) == splitter) {
			result[index]
		}
	}
}