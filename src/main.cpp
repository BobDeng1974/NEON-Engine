#include "Engine.cpp"
#include "string.cpp"
#include "Array.h"

#include <iostream>

int main()
{
	Array<int> array(10);
	array[0] = 9;

	for(int i = 0; i < array.length; i++)
		std::cout << array[i];

	return 0;
}