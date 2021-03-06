#pragma once

#include <cstdint>
#include <cstring>

template<class T>
struct Array
{
	public:
		T* array;

		std::size_t size; // Actual size of allocated memory
		uint32_t length; // Number of elements 

		Array() :
		array(new T[10]), size(10), length(0) {

		}

		Array(T* items, uint32_t size) {
			array = items;
			length = size;
		}

		Array(std::size_t size) {
			this->size = size;
			array = new T[size];
			length = 0;
		}

		void add(const T item)
		{
			if(size == length + 1)
			{
				size += 50;
				T* tempArr = new T[size];
				memcpy(tempArr, array, length * sizeof(T));
				delete array;
				array = tempArr;
			}
			array[length] = item;
			length++;
		}

		void remove(T item){
			for(uint32_t i = 0; i < length; i++)
			{
				if(array[i] == item)
				{
					if(i < length - 1)
						memcpy(array + i, array + i + 1, sizeof(T) * (length - i - 1));
					else
						array[length - 1] = nullptr;

					length--;
				}
			}
		}

		void removeAt(uint32_t index) {
			if(index >= length)
				return;
			if(index < length - 1)
				memcpy(array + index, array + index + 1, (length - index - 1) * sizeof(T));
			length--;
		}

		bool contains(T item) {
			for(uint32_t i = 0; i < length; i++)
				if(array[i] == item)
					return true;

			return false;
		}

		T* trim(uint32_t index) {
			T trims = new T[2];
			memcpy(trims[0], array, index * sizeof(T));
			memcpy(trims[1], array + index, length - index);
		}

		void copy(T* destination) {
			memcpy(destination, &array, length * sizeof(T));
		}

		void copy(T* destination, uint32_t length) {
			memcpy(destination, &array, length * sizeof(T));
		}

		T& operator[](const std::size_t index) const {
			return array[index];
		}
};