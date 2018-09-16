#include "Vector4.h"
#include <cmath>

Vector4::Vector4() :
x(0.0f), y(0.0f), z(0.0f), w(1.0f)
{
	
}

Vector4::Vector4(float value) :
x(value), y(value), z(value), w(1.0f)
{

}

Vector4::Vector4(float x, float y, float z) :
x(x), y(y), z(z), w(1.0f)
{

}

Vector4::Vector4(float x, float y, float z, float w) :
x(x), y(y), z(z), w(w)
{

}

void Vector4::calculateMagnitude() {
	this->magnitude = sqrt(x * x + y * y + z * z);
}

void Vector4::normalize() {
	this->x /= magnitude;
	this->y /= magnitude;
	this->z /= magnitude;
}

Vector4 Vector4::normalized() {
	return Vector4(this->x / magnitude, this->y / magnitude, this->z / magnitude);
}

Vector4 Vector4::operator+(const Vector4& vec) {
	return Vector4(this->x + vec.x, this->y + vec.y, this->z + vec.z);
}
Vector4 Vector4::operator+(const float& value) {
	return Vector4(this->x + value, this->y + value, this->z + value);
}

Vector4 Vector4::operator-(const Vector4& vec) {
	return Vector4(this->x - vec.x, this->y - vec.y, this->z - vec.z);
}
Vector4 Vector4::operator-(const float& value) {
	return Vector4(this->x - value, this->y - value, this->z - value);
}