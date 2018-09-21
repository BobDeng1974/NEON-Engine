#include <cstdint>
#include <iostream>

struct string
{
	private:
		char* characters;

	public:
		std::size_t size; // Actual reserved size
		std::size_t length; // Length of string

		// Initialize new string with space for 8 characters
		string();
		// Initialize new string with specified space
		string(const std::size_t size);
		string(char str[]);
		string(char* str, const uint32_t length);

		// Determine if string starts with specified token
		bool startsWith(string* token);

		// Splits string
		string* split(char splitter, uint32_t& splitCount);

		// Converts string into int32_t
		int32_t toInt32();

		// Gets characters
		char* data();
		// Get character on specific position
		char get(uint32_t index);
		// Copies data
		void copyTo(char* target, uint32_t start, std::size_t size);
		void copyHere(char* source, uint32_t start, std::size_t size);

		void realloc(std::size_t newSize);
		// Adds another string
		// ===================
		void add(char* str, std::size_t size);
		void add(const string str);

		// Operator overloading
		// ====================
		string operator+(const string& str);
		string operator+(const char*& str);

		string& operator+=(const string& str);
		string& operator+=(const char& str);

		bool operator==(const char* str1);

		string& operator=(string str);

		friend std::ostream& operator<<(std::ostream& stream, const string& str);
		friend std::istream& operator>>(std::istream& stream, const string& str);

		operator char*() const;

		char& operator[](std::size_t index) const;
};