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
			std::cout << i << " " << splitIndex;
			memcpy(splits[splitCount].data(), this->characters + splitIndex, (i - splitIndex) * sizeof(char));
			splitCount++;
			splitIndex = i;
			std::cout << splits[splitCount - 1].data() << std::endl;
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

string string::operator+(const string& str) {
	string newString(this->length + str.length);
	memcpy(&newString.characters, this->characters, this->length * sizeof(char));
	memcpy(&newString + this->length, str.characters, str.length);
}

char& string::operator[](std::size_t index) {
	return this->characters[index]; 
}

bool string::operator==(string& str) const {
	for(uint32_t i = 0; i < length; i++)
		if(str[i] != this->characters[i])
			return false;

	return true;
}