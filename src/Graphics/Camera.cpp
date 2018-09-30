#include "Camera.h"

Camera::Camera() {
	this->position = glm::vec3(0.0f, 0.0f, 0.0f);
}

Camera::Camera(glm::vec3 initialPosition) {
	this->position = initialPosition;
}

void Camera::move(glm::vec3 move) {
	
}