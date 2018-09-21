#include <cstdint>

struct Block{
	public:
		uint32_t index;
		uint32_t size;

		Block();
		Block(uint32_t index, uint32_t size);
};