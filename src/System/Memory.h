#include <cstdint>
#include <cstring>

namespace Memory
{
	template<class T>
	T* Realloc(T* source, std::size_t sourceSize, std::size_t size)
	{
		T* pointer = new T[size];
		std::memcpy(pointer, source, sourceSize);
		delete source;

		return pointer;
	}

	template<class T>
	void Copy(T* source, T* destination, std::size_t size)
	{
		std::memcpy(destination, source, size);
	}
}