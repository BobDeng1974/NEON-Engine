#include "Vector3.h"
#include <cmath>

Vector3::Vector3() :
x(0.0f), y(0.0f), z(0.0f)
{
	
}

Vector3::Vector3(float value) :
x(value), y(value), z(value)
{

}

Vector3::Vector3(float x, float y, float z) :
x(x), y(y), z(z)
{

}

void Vector3::calculateMagnitude() {
	this->magnitude = sqrt(x * x + y * y + z * z);
}

void Vector3::normalize() {
	this->x /= magnitude;
	this->y /= magnitude;
	this->z /= magnitude;
}

Vector3 Vector3::normalized() {
	return Vector3(this->x / magnitude, this->y / magnitude, this->z / magnitude);
}

Vector3 Vector3::operator+(const Vector3& vec) {
	return Vector3(this->x + vec.x, this->y + vec.y, this->z + vec.z);
}
Vector3 Vector3::operator+(const float& value) {
	return Vector3(this->x + value, this->y + value, this->z + value);
}

Vector3 Vector3::operator-(const Vector3& vec) {
	return Vector3(this->x - vec.x, this->y - vec.y, this->z - vec.z);
}
Vector3 Vector3::operator-(const float& value) {
	return Vector3(this->x - value, this->y - value, this->z - value);
}