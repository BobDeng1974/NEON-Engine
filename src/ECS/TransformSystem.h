#include <cstdint>

#include "TransformComponent.h"

class TransformSystem {
	uint32_t componentCount = 0;
	TransformComponent components[];

	public:
		void onUpdate() {
			for(uint32_t i = 0; i < componentCount; i++) {
				
			}
		}
};