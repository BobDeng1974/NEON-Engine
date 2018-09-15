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
characters(str), length(28), size(28) {

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

string* string::split(char splitter, uint32_t* count)
{
	count = new uint32_t;
	for(uint32_t i = 0; i < this->length; i++)
		if(splitter == this->get(i))
			count++;

	string* splits = new string[*count];

	uint32_t splitIndex = 0;
	uint32_t splitCount = 0;

	for(uint32_t i = 0; i < this->length; i++)
	{
		if(splitter == this->get(i))
		{
			this->copy(splits[splitCount].characters, splitIndex, i - splitIndex);
			splits[splitCount].size = i - splitIndex;
			splits[splitCount].length = i - splitIndex;
		}
	}
}

void string::copy(char* target, uint32_t start, std::size_t size)
{
	target = new char[size];
	memcpy(target, this->characters + start, size);
}

char string::get(std::size_t index){
	return this->characters[index];
}

char& string::operator[](std::size_t index) {
	return this->characters[index]; 
}