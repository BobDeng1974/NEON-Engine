struct Vector4 {
	public:
		float x;
		float y;
		float z;

		float w;

		float magnitude;

		Vector4();
		Vector4(float value);
		Vector4(float x, float y, float z);
		Vector4(float x, float y, float z, float w);
		Vector4(Vector4& vector);

		void calculateMagnitude();

		float dot();
		Vector4 cross(Vector4 vector);

		Vector4& operator+(const Vector4& vector);
		Vector4& operator+(const float& value);

		Vector4& operator-(const Vector4& vector);
		Vector4& operator-(const float& value);

		Vector4& operator*(const Vector4& vector);
		Vector4& operator*(const float& value);

		Vector4& operator/(const Vector4& vector);
		Vector4& operator/(const float& value);

		Vector4& operator==(const Vector4& vector);
};