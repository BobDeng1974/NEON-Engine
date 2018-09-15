#include <cstdint>

struct string
{
	private:
		char* characters;

	public:
		std::size_t size; // Actual reserved size
		std::size_t length; // Length of string

		string();
		string(std::size_t size);
		string(char str[]);
		string(char* str, uint32_t length);

		bool startsWith(string* token);
		string* split(char splitter, uint32_t& splitCount);

		char* data();
		char get(std::size_t index);
		void copy(char* target, uint32_t start, std::size_t size);

		string operator+(string str);
		string operator+(char str);

		void operator+=(string str);
		void operator+=(char str);

		char& operator[](std::size_t index);
};