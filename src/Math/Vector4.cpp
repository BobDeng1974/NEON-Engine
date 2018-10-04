#include <cstring>
#include <math.h>

#include "Vector4.h"

#pragma region Constructors
Vector4::Vector4() :
x(0.0f), y(0.0f), z(0.0f), w(1.0f) {

}

Vector4::Vector4(const float value) : 
x(value), y(value), z(value), w(1.0f) {

}

Vector4::Vector4(const float x, const float y, const float z) :
x(x), y(y), z(z), w(1.0f) {

}

Vector4::Vector4(const float x, const float y, const float z, const float w) :
x(x), y(y), z(z), w(w) {

}

Vector4::Vector4(const Vector3& vector) :
w(1.0f) {
	memcpy(this, &vector, 3 * sizeof(float));
}

Vector4::Vector4(const Vector4& vector) {
	memcpy(this, &vector, 4 * sizeof(float));
}
#pragma endregion

void Vector4::calculateMagnitude() {
	this->magnitude = sqrt(x * x + y * y + z * z);
}

void Vector4::normalize() {
	this->x /= magnitude;
	this->y /= magnitude;
	this->z /= magnitude;
}

Vector4* Vector4::normalized() {
	return new Vector4(this->x /= magnitude, this->y /= magnitude, this->z /= magnitude);
}

float Vector4::dot(Vector4& other) {
	return (this->x * other.x) + (this->y * other.y) + (this->z * other.z);
}

Vector4* Vector4::cross(const Vector4& vector) {
	return new Vector4(this->y * vector.z - this->z * vector.y, this->z * vector.x - this->x * vector.z, this->x * vector.y - this->y * vector.x);
}

#pragma region Addition
Vector4& Vector4::operator+(const Vector4& vector) {
	Vector4 result(this->x + vector.x, this->y + vector.y, this->z + vector.z);
	return result;
}

Vector4& Vector4::operator+(const Vector3& vector) {
	Vector4 result(this->x + vector.x, this->y + vector.y, this->z + vector.z);
	return result;
}

Vector4& Vector4::operator+(const float& value) {
	Vector4 result(this->x + value, this->y + value, this->z + value);
	return result;
}
#pragma endregion

#pragma region Substraction
Vector4& Vector4::operator-(const Vector4& vector) {
	Vector4 result(this->x - vector.x, this->y - vector.y, this->z - vector.z);
	return result;
}

Vector4& Vector4::operator-(const Vector3& vector) {
	Vector4 result(this->x - vector.x, this->y - vector.y, this->z - vector.z);
	return result;
}

Vector4& Vector4::operator-(const float& value) {
	Vector4 result(this->x - value, this->y - value, this->z - value);
	return result;
}
#pragma endregion

#pragma region Multiplication
Vector4& Vector4::operator*(const Vector4& vector) {
	Vector4 result(this->x * vector.x, this->y * vector.y, this->z * vector.z);
	return result;
}

Vector4& Vector4::operator*(const Vector3& vector) {
	Vector4 result(this->x * vector.x, this->y * vector.y, this->z * vector.z);
	return result;
}

Vector4& Vector4::operator*(const float& value) {
	Vector4 result(this->x * value, this->y * value, this->z * value);
	return result;
}
#pragma endregion

#pragma region Division
Vector4& Vector4::operator/(const Vector4& vector) {
	Vector4 result(this->x / vector.x, this->y / vector.y, this->z / vector.z);
	return result;
}

Vector4& Vector4::operator/(const Vector3& vector) {
	Vector4 result(this->x / vector.x, this->y / vector.y, this->z / vector.z);
	return result;
}

Vector4& Vector4::operator/(const float& value) {
	Vector4 result(this->x / value, this->y / value, this->z / value);
	return result;
}
#pragma endregion

Vector4& Vector4::operator=(const Vector4& vector) {
	memcpy(this, &vector, sizeof(Vector4));
}

bool& Vector4::operator==(const Vector4& vector) {
	bool result = this->x == vector.x && this->y == vector.y && this->z == vector.z;
	
	return result;
}