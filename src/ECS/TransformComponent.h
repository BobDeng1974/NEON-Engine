#include "Transform.h"

struct TransformComponent {
	Transform* transform;

	Vector3 move;
	Vector3 rotation;
	Vector3 scale;
};