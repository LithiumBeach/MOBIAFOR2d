#include "Vector2.h"

using namespace mob_core::math;

typedef Vector2::real real;
		
real Vector2::Magnitude() const
{
	return sqrt(SqrMagnitude());
}

real Vector2::SqrMagnitude() const
{
	return (x * x) + (y * y);
}

void Vector2::Normalize()
{
	real magnitude = Magnitude();
	if (magnitude > 0)
	{
		*this /= magnitude;
	}
}

Vector2 Vector2::Normalized() const
{
	real magnitude = Magnitude();
	if (magnitude > 0)
	{
		return *this / magnitude;
	}
	return *this;
}

real Vector2::Dot(const Vector2& a_v) const
{
	return (x * a_v.x) + (y * a_v.y);
}