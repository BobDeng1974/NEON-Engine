#include <cstdint>

#include "TransformComponent.h"
#include "Matrix4x4.cpp"

class TransformSystem {
	uint32_t componentCount = 0;
	TransformComponent components[];

	public:
		void onUpdate() {
			for(uint32_t i = 0; i < componentCount; i++) {
				components[i].transform->transform.translate(components[i].move);
				components[i].transform->transform.rotate(components[i].rotation);
				components[i].transform->transform.scale(components[i].scale);
			}
		}
};