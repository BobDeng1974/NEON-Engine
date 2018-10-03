struct Vector3 {
	public:
		float x;
		float y;
		float z;

		float magnitude;

		Vector3();
		Vector3(float value);
		Vector3(float x, float y, float z);
		Vector3(Vector3& vector);

		void calculateMagnitude();
		void normalize();

		Vector3 normalized();

		float dot();
		Vector3 cross(Vector3 vector);

		Vector3& operator+(const Vector3& vector);
		Vector3& operator+(const float& value);

		Vector3& operator-(const Vector3& vector);
		Vector3& operator-(const float& value);

		Vector3& operator*(const Vector3& vector);
		Vector3& operator*(const float& value);

		Vector3& operator/(const Vector3& vector);
		Vector3& operator/(const float& value);

		Vector3& operator=(const Vector3& vector);
		bool& operator==(const Vector3& vector);
};