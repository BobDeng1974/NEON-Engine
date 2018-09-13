#include <cstdint>
#include <cstring>

template<class T>
struct Array
{
	public:
		T* array;

		std::size_t size; // Actual size of allocated memory
		uint32_t length; // Number of elements 

		Array(T* items, uint32_t size)
		{
			array = items;
			length = size;
		}

		Array(std::size_t size)
		{
			this->size = size;
			array = new T[size];
			length = 0;
		}

		void Allocate(size_t count)
		{

		}

		void Add(T item)
		{
			if(size == length)
			{
				size += 10;
				realloc(array, size);

				array[length] = item;
			}	else
				array[length] = item;

			length++;
		}
		void Add(Array<T> items);
		void Add(T* items, uint32_t length);

		bool Remove(T item);
		bool RemoveAt(uint32_t index);

		void copy(T* destination)
		{
			memcpy(destination, array, length * sizeof(T));
		}
};