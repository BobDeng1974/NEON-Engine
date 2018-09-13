#include "string.h"
#include "Memory.h"

#include <string>

string::string(char* string) :
characters(string)
{

}

string::string(uint32_t length)
{
	this->length = length;
	this->characters = new char[length];
}

string string::operator+(const string& str)
{
	this->length += length;
	this->characters = Memory::Realloc(&str, str.length * sizeof(char*), this->length + str.length)->characters;

	return *this;
}