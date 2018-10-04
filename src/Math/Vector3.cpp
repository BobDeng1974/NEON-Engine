#include <cstring>
#include <math.h>

#include "Vector3.h"
#include "Vector4.cpp"

#pragma region Constructors
Vector3::Vector3() :
x(0.0f), y(0.0f), z(0.0f) {

}

Vector3::Vector3(const float value) : 
x(value), y(value), z(value) {

}

Vector3::Vector3(const float x, const float y, const float z) :
x(x), y(y), z(z) {

}

Vector3::Vector3(const Vector3& vector) {
	memcpy(this, &vector, 3 * sizeof(float));
}

Vector3::Vector3(const Vector4& vector) {
	memcpy(this, &vector, 3 * sizeof(float));
}
#pragma endregion

void Vector3::calculateMagnitude() {
	this->magnitude = sqrt(x * x + y * y + z * z);
}

void Vector3::normalize() {
	this->x /= magnitude;
	this->y /= magnitude;
	this->z /= magnitude;
}

Vector3* Vector3::normalized() {
	return new Vector3
(this->x /= magnitude, this->y /= magnitude, this->z /= magnitude);
}

float Vector3::dot(Vector3& other) {
	return (this->x * other.x) + (this->y * other.y) + (this->z * other.z);
}

Vector3* Vector3::cross(const Vector3& vector) {
	return new Vector3
(this->y * vector.z - this->z * vector.y, this->z * vector.x - this->x * vector.z, this->x * vector.y - this->y * vector.x);
}

#pragma region Addition
Vector3& Vector3::operator+(const Vector4& vector) {
	Vector3
 result(this->x + vector.x, this->y + vector.y, this->z + vector.z);
	return result;
}

Vector3& Vector3::operator+(const Vector3& vector) {
	Vector3
 result(this->x + vector.x, this->y + vector.y, this->z + vector.z);
	return result;
}

Vector3& Vector3::operator+(const float& value) {
	Vector3
 result(this->x + value, this->y + value, this->z + value);
	return result;
}
#pragma endregion

#pragma region Substraction
Vector3& Vector3::operator-(const Vector3& vector) {
	Vector3
 result(this->x - vector.x, this->y - vector.y, this->z - vector.z);
	return result;
}

Vector3& Vector3::operator-(const Vector4& vector) {
	Vector3
 result(this->x - vector.x, this->y - vector.y, this->z - vector.z);
	return result;
}

Vector3& Vector3::operator-(const float& value) {
	Vector3
 result(this->x - value, this->y - value, this->z - value);
	return result;
}
#pragma endregion

#pragma region Multiplication
Vector3& Vector3::operator*(const Vector3& vector) {
	Vector3
 result(this->x * vector.x, this->y * vector.y, this->z * vector.z);
	return result;
}

Vector3& Vector3::operator*(const Vector4& vector) {
	Vector3
 result(this->x * vector.x, this->y * vector.y, this->z * vector.z);
	return result;
}

Vector3& Vector3::operator*(const float& value) {
	Vector3
 result(this->x * value, this->y * value, this->z * value);
	return result;
}
#pragma endregion

#pragma region Division
Vector3& Vector3::operator/(const Vector3& vector) {
	Vector3
 result(this->x / vector.x, this->y / vector.y, this->z / vector.z);
	return result;
}

Vector3& Vector3::operator/(const Vector4& vector) {
	Vector3
 result(this->x / vector.x, this->y / vector.y, this->z / vector.z);
	return result;
}

Vector3& Vector3::operator/(const float& value) {
	Vector3
 result(this->x / value, this->y / value, this->z / value);
	return result;
}
#pragma endregion

Vector3& Vector3::operator=(const Vector3& vector) {
	memcpy(this, &vector, sizeof(Vector3
));
}

bool& Vector3::operator==(const Vector3& vector) {
	bool result = this->x == vector.x && this->y == vector.y && this->z == vector.z;
	
	return result;
}