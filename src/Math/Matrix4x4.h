#pragma once
#include "Array.h"

#include "Vector3.cpp"
#include "Vector4.cpp"
#include "Quaternion.cpp"

struct Matrix4x4
{
	public:
		float M11, M21, M31, M41;
		float M12, M22, M32, M42;
		float M13, M23, M33, M43;
		float M14, M24, M34, M44;

		Matrix4x4(float value);
		Matrix4x4(float* values, uint32_t length);
		Matrix4x4(Array<float> array);

		Matrix4x4 identity();

		void translate(Vector3 translation);
		void translate(Vector4 translation);

		Matrix4x4 translation(Vector3 translation);
		Matrix4x4 translation(Vector4 translation);

		void rotate(Quaternion rotation);
		void rotate(Vector3 rotation);
		void rotate(Vector4 rotation);

		Matrix4x4 rotation(Quaternion rotation);
		Matrix4x4 rotation(Vector3 rotation);
		Matrix4x4 rotation(Vector4 rotation);

		void scale(Vector3 scale);
		void scale(Vector4 scale);

		Matrix4x4 scaled(Vector3 scale);
		Matrix4x4 scaled(Vector4 scale);
};