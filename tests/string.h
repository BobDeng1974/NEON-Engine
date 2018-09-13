#include <cstdint>

struct string
{
	private:

	public:
		char* characters;
		uint32_t length;

		// Creates new string with specified charactersS
		string(char* string);
		// Create new string and free space for the characters
		string(uint32_t length);

		bool startsWith(char* str);
		bool startsWith(char c);

		void reinitialize(uint32_t length);

		char operator[](const std::size_t index);

		string operator+(const string& str);
		void operator=(const string& str);
};