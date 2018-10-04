#include "Vector3.h"

struct Vector4 {
	public:
		float x;
		float y;
		float z;

		float w;

		float magnitude;

		Vector4();
		Vector4(const float value);
		Vector4(const float x, const float y, const float z);
		Vector4(const float x, const float y, const float z, const float w);
		Vector4(const Vector3& vector);
		Vector4(const Vector4& vector);

		void calculateMagnitude();
		void normalize();

		Vector4* normalized();

		float dot(Vector4& other);
		Vector4* cross(const Vector4& vector);

		Vector4& operator+(const Vector3& vector);
		Vector4& operator+(const Vector4& vector);
		Vector4& operator+(const float& value);

		Vector4& operator-(const Vector4& vector);
		Vector4& operator-(const Vector3& vector);
		Vector4& operator-(const float& value);

		Vector4& operator*(const Vector4& vector);
		Vector4& operator*(const Vector3& vector);
		Vector4& operator*(const float& value);

		Vector4& operator/(const Vector4& vector);
		Vector4& operator/(const Vector3& vector);
		Vector4& operator/(const float& value);

		Vector4& operator=(const Vector4& vector);
		bool& operator==(const Vector4& vector);
};