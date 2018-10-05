#include "Transform.h"

struct RenderComponent {
	Transform* transform;

	public:
		RenderComponent(Transform* transform) : 
		transform(transform) {
			
		}
};