#include <cstring>

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