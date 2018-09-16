struct Vector3
{
	public:
		float x;
		float y;
		float z;
		
		float magnitude;

		Vector3();
		Vector3(float value);
		Vector3(float x, float y, float z);

		void calculateMagnitude();

		void normalize();
		Vector3 normalized();

		Vector3 operator+(const Vector3& vec);
		Vector3 operator+(const float& value);

		void operator+=(const Vector3& vec);
		void operator+=(const float& vec);

		Vector3 operator-(const Vector3& vec);
		Vector3 operator-(const float& value);

		void operator-=(const Vector3& vec);
		void operator+=(const float& value);

		Vector3 operator*(const float& value);
		Vector3 operator/(const float& value);
};