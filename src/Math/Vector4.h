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

		float dot();

		Vector4 cross();

		void calculateMagnitude();

		void normalize();
		Vector4 normalized();
};
