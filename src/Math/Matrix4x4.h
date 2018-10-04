#include "Vector3.h"
#include "Vector4.h"

struct Matrix4x4 {
	public:
		float M11, M21, M31, M41;
		float M12, M22, M32, M42;
		float M13, M23, M33, M43;
		float M14, M24, M34, M44;

		Vector3 translation() const;
		Vector3 rotation() const;
		Vector3 scale() const;

		Matrix4x4();
		Matrix4x4(const float& value);
		Matrix4x4(const float*& values);

		void translate(const Vector3& translation);
		void translate(const Vector4& translation);
		void translate(const float x, const float y, const float z);

		void rotate(const Vector3& rotation);
		void rotate(const Vector4& rotation);
		void rotate(const float x, const float y, const float z);

		void scale(const Vector3& scale);
		void scale(const Vector4& scale);
		void scale(const float x, const float y, const float z);

		Matrix4x4 operator+(const float& value);
		Matrix4x4 operator+(const Matrix4x4& other);

		Matrix4x4 operator-(const float& value);
		Matrix4x4 operator-(const Matrix4x4& other);

		Matrix4x4 operator*(const float& value);
		Matrix4x4 operator*(const Matrix4x4& other);
};

namespace Matrix {
	Matrix4x4 identity();
}