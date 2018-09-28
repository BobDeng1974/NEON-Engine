#include "Debug.h"
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
characters(str), length(getLength()), size(getLength()) {
	
}

string::string(char* str, uint32_t length) : 
characters(str), length(length), size(length) {

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

void string::split(const char splitter, string**& splits, uint32_t& splitCount) {
	// Gets number of splits
	uint32_t splitIndex = 0;
	uint32_t resultIndex = 0;
	for(uint32_t i = 0; i != this->length; i++) {
		if(this->get(i) == splitter || this->get(i) == '\0') {
			if(splitIndex + 1 == i) {
				continue;
			} else {
				splitCount++;
				i++;
				splitIndex = i;
			}
		}
	}

	splitIndex = 0;
	splits = new string*[splitCount];

	for(uint32_t i = 0; i != this->length + 1; i++) {
		if(this->get(i) == splitter || this->get(i) == '\0') {
			if(splitIndex == i) {
				splitIndex++;
				continue;
			} else {
				splits[resultIndex] = new string(i - splitIndex);
				memcpy(splits[resultIndex]->characters, this->characters + splitIndex, i - splitIndex);
				splits[resultIndex]->length = i - splitIndex;
				splitIndex = i;
				splitIndex++;
				resultIndex++;
			}
		}
	}
}

// Returns
// =======
int32_t string::toInt32() {
	return std::stoi(characters);
}

float string::toFloat() {
	return std::stof(characters);
}

char* string::data() {
	return characters;
}

char string::get(uint32_t index) { 
	return characters[index];
}

uint32_t string::getLength() {
	for(uint32_t i = 0; ; i++) {
		if(this->characters[i] == '\0') {
			return i;
		}
	}
}

// Copying
// =======
void string::copyTo(char* target, uint32_t start, std::size_t size) {
	std::memcpy(target, this->characters, size);
}

void string::copyHere(char* source, uint32_t start, std::size_t size) {
	if(size > size){
		delete characters; // Release characters
		this->characters = new char[size]; // Initialize new place for characters

		this->size = size;
		this->length = length;
	}

	memcpy(this->characters, source, size);
}

// Addition
// ========
void string::add(char* str, std::size_t size) {
	char* temp;
	if(this->size < size + this->length) {
		this->size = size + this->size;
		temp = new char[this->size];
		memcpy(temp, this->characters, this->length);
	}

	memcpy(this->characters + this->length, str, size);
	this->length += size;
}

void string::realloc(std::size_t size) {
	char* tmp = new char[size];

	memcpy(tmp, this->characters, size);
	delete this->characters;

	this->characters = tmp;

	this->size = size;
	if(size > this->length)
		this->length = size;
}

// Operator Overloading
// ====================
string string::operator+(const string& str) {
	char* temp;

	if(this->size < str.size + this->length) {
		this->size = str.size + this->size;
		temp = new char[this->size];
		memcpy(temp, this->characters, this->length);
	}

	memcpy(this->characters + this->length, str.characters, size);
	this->length += str.size;
}

string string::operator+(const char*& str) {

}

string& string::operator+=(const string& str) {
	
}

string& string::operator+=(const char*& str) {
	
}

bool string::operator==(char*& str) const {
	return strcmp(this->characters, str) == 0;
}

bool string::operator==(const char* str) const {
	return strcmp(this->characters, str);
}


bool string::operator==(const char*& str) const {
	return strcmp(this->characters, str);
}


bool string::operator!=(char*& str) {
	return false;
}

string& string::operator=(const string& str)
{
	delete characters;
	characters = new char[str.length];

	this->characters = str.characters;
	this->length = str.length;
	this->size = str.length;
}

char& string::operator[](std::size_t index) const {
	return characters[index];
}