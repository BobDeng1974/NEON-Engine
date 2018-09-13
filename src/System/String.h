#pragma once

#include <iostream>
#include <cstring>
#include <cstdint>

#include "Array.h"
#include "Memory.h"

namespace String
{
	char** Split(char* str, uint32_t strLength, char splitter, uint32_t* count)
	{
		uint32_t splitCount = 1;
		for(uint32_t i = 0; i < strLength; i++)
			if(str[i] == splitter)
				splitCount++;

		count = &splitCount;
		std::cout << splitCount;

		uint32_t index = 0;
		uint32_t splitIndex = 0;
		char** splits = new char*[splitCount];

		uint32_t x = 0;
		uint32_t y = 0;

		for(uint32_t i = 0; i < strLength; i++)
		{
			if(str[i] == splitter)
			{
				splits[x] = new char[i - y];
				y = i;
				x++;
			}
		}
		std::cout << sizeof(splits);

		for(uint32_t i = 0; i < strLength; i++)
		{
			if(str[i] == splitter)
			{
				std::memcpy(splits[splitIndex], str + index, sizeof(char) * (i - index));
				splitIndex++;
				index = ++i;
			}
		}

		for(int i = 0; i < splitCount; i++)
			std::cout << splits[i] << std::endl;

		return splits;
	}
}