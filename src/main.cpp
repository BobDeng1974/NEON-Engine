#include "Engine.cpp"
#include "string.cpp"
#include "Array.h"

#include <iostream>

int main()
{
	Array<int> array(10);
	array.add(5);
	array.add(8);
	array.add(9);
	array.add(15);
	for(int i = 0; i < array.length; i++)
		std::cout << array[i];

	array.removeAt(0);

	for(int i = 0; i < array.length; i++)
		std::cout << array[i];

	if(array.contains(8))
		std::cout << "pepa";

	return 0;
}