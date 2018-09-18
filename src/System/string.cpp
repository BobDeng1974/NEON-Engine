#include <cstring>

#include "string.hpp"

string::string() :
characters(new char[16]), length(0), size(16){

} 

string::string(std::size_t size) :
size(size), length(0.0f) {
	characters = new char[size];
}

string::string(char str[]) :
characters(str) {
	uint32_t lgt = getLength();

	length = lgt;
	size = lgt;
}

string::string(char* str, uint32_t length) :
characters(str), length(length), size(length) {

}

bool string::startsWith(string* token)
{
	for(uint32_t i = 0; i < token->length; i++)
		if(token->get(i) != this->get(i))
			return false;

	return true;
}

char* string::data() {
	return characters;
}

void string::add(char* str, std::size_t size)
{
	char* result = new char[this->length + size];

	memcpy(result, this->characters, this->length);
	memcpy(result + this->length, str, 10);

	delete characters;
	characters = result;
}

string* string::split(char splitter, uint32_t& count)
{
	count = 1;
	for(uint32_t i = 0; i < this->length; i++)
		if(splitter == this->get(i))
			count++;

	string* splits = new string[count];

	uint32_t splitIndex = 0;
	uint32_t splitCount = 0;

	for(uint32_t i = 0; i < this->length; i++)
	{
		if(splitter == this->get(i))
		{
			i++;
			memcpy(splits[splitCount].data(), this->characters + splitIndex, (i - splitIndex) * sizeof(char));
			splitCount++;
			splitIndex = i;
		}
	}
	memcpy(splits[splitCount].data(), this->characters + splitIndex, (length - 1 - splitIndex) * sizeof(char));

	return splits;
}

void string::copy(char* target, uint32_t start, std::size_t size)
{
	target = new char[size];
	target = (char*)memcpy(target, this->characters + start, size);
}

char string::get(std::size_t index){
	return this->characters[index];
}

uint32_t string::getLength() {
	for(int i = 0; ; i++)
		if(this->characters[i] == '\0')
			return i;
}

#pragma region Operator Overloading
//
// Operator overloading functions
// ==============================

string string::operator+(const string& str) {
	string newString(this->length + str.length);
	memcpy(&newString.characters, this->characters, this->length);
	memcpy(&newString + this->length, str.characters, str.length);
}

string string::operator+(const char*& str) {
	string newString(this->length + strlen(str));
	memcpy(&newString.characters, this->characters, this->length);
	memcpy(&newString + this->length, str, strlen(str));
}

char& string::operator[](std::size_t index) const{
	return this->characters[index]; 
}

bool string::operator==(const string& str) const{
	for(uint32_t i = 0; i < length; i++)
		if(str[i] != this->characters[i])
			return false;

	return true;
}

bool string::operator==(const char*& str) const {
	for(uint32_t i = 0; i < length; i++)
		if(str[i] != '\0' && str[i] != this->characters[i])
			return false;

	return true;
}

void string::operator=(const string& str) const{
	this->
}

string::operator char *() const {
	return characters;
}
#pragma endregion