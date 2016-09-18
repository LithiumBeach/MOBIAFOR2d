#include "Transform.h"

using namespace mob_core::math;

void Transform::LookAt(Vector2 a_point)
{//I really don't like this workaround for the zero vector -- brain cursor.
	//if either are the zero vector;
	Vector2 c_position = position;
	if (c_position == Vector2(0) || a_point == Vector2(0))
	{
		if (a_point == Vector2(0, -1))
		{
			a_point += Vector2(2);
			c_position += Vector2(2);
		}
		else
		{
			a_point += Vector2(1);
			c_position += Vector2(1);
		}
	}
	rotation = acos(position.Normalized().Dot(a_point.Normalized()));
}