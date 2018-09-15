#include "Engine.cpp"
#include "string.cpp"

#include <iostream>

int main()
{
	string str("Dneska je ale pekne pocasi!", 28);

	std::cout << str.length << std::endl;

	uint32_t count = 0;
	string* splits = str.split(' ', &count);
	std::cout << count << std::endl;

	return 0;
}