struct Vector4
{
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

		void calculateMagnitude();

		void normalize();
		Vector4 normalized();

		Vector4 operator+(const Vector4& vec);
		Vector4 operator+(const float& value);

		void operator+=(const Vector4& vec);
		void operator+=(const float& vec);

		Vector4 operator-(const Vector4& vec);
		Vector4 operator-(const float& value);

		void operator-=(const Vector4& vec);
		void operator+=(const float& value);

		Vector4 operator*(const float& value);
		Vector4 operator/(const float& value);
};
