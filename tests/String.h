#include "string.cpp"
#include "Memory.h"

#include <string>

namespace String
{
	string* Split(string str, char splitter)
	{
		uint32_t cuts = 0;
		for(uint32_t i = 0; i < str.length; i++)
			if(str[i] == splitter)
				cuts++;

		string* splits = new string[cuts];
		uint32_t splitCount = 0;

		uint32_t cutIndex = 0;
		for(uint32_t i = 0; i < str.length; i++)
		{
			if(str[i] == splitter)
			{
				char* split = new char[i - cutIndex];
				Memory::Copy<char>(str + sizeof(char) * cutIndex, split, (i - cutIndex * sizeof(char)));

				splits[splitCount] = split;
				cutIndex = i;
				splitCount++;
			}
		}
	}
}