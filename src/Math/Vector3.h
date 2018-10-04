struct Vector3 {
	public:
		float x;
		float y;
		float z;

		float w;

		float magnitude;

		Vector3();
		Vector3(const float value);
		Vector3(const float x, const float y, const float z);
		Vector3(const Vector3& vector);
		Vector3(const Vector4& vector);

		void calculateMagnitude();
		void normalize();

		Vector3* normalized();

		float dot(Vector3& other);
		Vector3* cross(const Vector3& vector);

		Vector3& operator+(const Vector3& vector);
		Vector3& operator+(const Vector4& vector);
		Vector3& operator+(const float& value);

		Vector3& operator-(const Vector3& vector);
		Vector3& operator-(const Vector4& vector);
		Vector3& operator-(const float& value);

		Vector3& operator*(const Vector3& vector);
		Vector3& operator*(const Vector4& vector);
		Vector3& operator*(const float& value);

		Vector3& operator/(const Vector3& vector);
		Vector3& operator/(const Vector4& vector);
		Vector3& operator/(const float& value);

		Vector3& operator=(const Vector3& vector);
		bool& operator==(const Vector3& vector);
};