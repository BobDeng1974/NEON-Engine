#include "Matrix4x4.h"
#include <math.h>

Matrix4x4::Matrix4x4(float value) :
M11(value), M21(value), M31(value), M41(value),
M12(value), M22(value), M32(value), M42(value),
M13(value), M23(value), M33(value), M43(value),
M14(value), M24(value), M34(value), M44(value) {
	
}

Matrix4x4::Matrix4x4(float* values, uint32_t length) {
	memcpy(&M11, values, length * sizeof(float));
}

Matrix4x4::Matrix4x4(Array<float> array) {
	array.copy(&M11);
}

Matrix4x4 Matrix4x4::identity() {
	float* values = new float[16] {
			1.0f, 0.0f, 0.0f, 0.0f,
			0.0f, 1.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 1.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 1.0f
		};

	return Matrix4x4(values, 16);
}


Matrix4x4 Matrix4x4::createPerspective(float fov, float aspect, float zNear, float zFar) {
	float yMax = zNear * tan(0.5f * fov);
	float yMin = -yMax;
	float xMin = yMin * aspect;
	float xMax = yMax * aspect;

	
}