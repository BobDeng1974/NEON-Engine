#include "String.h"

#include <iostream>

int main()
{
	std::cout << "pepa";
	char* pepa = (char*)"dneska je ale pekne pocasi ze?";
	char** splits = String::Split(pepa, 30, ' ');

	/*for(int i = 0; i < 6; i++)
		std::cout << splits[i];*/

	return 0;
}