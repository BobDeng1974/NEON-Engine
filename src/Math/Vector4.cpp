#include "Vector4.h"

Vector4::Vector4() :
x(0.0f), y(0.0f), z(0.0f), w(1.0f)
{
	
}

Vector4::Vector4(float value) :
x(value), y(value), z(value), w(1.0f)
{

}

Vector4::Vector4(float x, float y, float z) :
x(x), y(y), z(z), w(1.0f)
{

}

Vector4::Vector4(float x, float y, float z, float w) :
x(x), y(y), z(z), w(w)
{

}