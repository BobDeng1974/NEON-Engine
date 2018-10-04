#include <cstring>

#include "Matrix4x4.h"

Matrix4x4::Matrix4x4() :
M11(1.0f), M21(0.0f), M31(0.0f), M41(0.0f),
M12(0.0f), M22(1.0f), M32(0.0f), M42(0.0f),
M13(0.0f), M23(0.0f), M33(1.0f), M43(0.0f),
M14(0.0f), M24(0.0f), M34(0.0f), M44(1.0f) {

}

Matrix4x4::Matrix4x4(const float& value) : 
M11(value), M21(value), M31(value), M41(value),
M12(value), M22(value), M32(value), M42(value),
M13(value), M23(value), M33(value), M43(value),
M14(value), M24(value), M34(value), M44(value) {

}

Matrix4x4::Matrix4x4(const float*& value) {
	memcpy(this, value, sizeof(float) * 16);
}

void Matrix4x4::translate(const Vector3& translation) {
	
}