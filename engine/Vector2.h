#ifndef VECTOR2_H
#define VECTOR2_H

#include <math.h>

namespace mob_core {
	namespace math {


		class Vector2
		{
		public:
			typedef float real;

		public:
			Vector2() : x(0), y(0){};
			Vector2(real a_x, real a_y) : x(a_x), y(a_y){};
			Vector2(real a_xy) : x(a_xy), y(a_xy){};
			Vector2(const Vector2& a_v) : x(a_v.x), y(a_v.y){};

		public:
			real x;
			real y;

		public:
			real Magnitude() const;
			real SqrMagnitude() const; //returns magnitude squared : no sqrt operation
			
			void Normalize(); //normalizes this
			Vector2 Normalized() const; //returns normalized vector w/o changing this

			real Dot(const Vector2& a_v) const;

		//overloads
		public:
			void operator*=(const real a_n)
			{
				x *= a_n;
				y *= a_n;
			}

			Vector2 operator*(const real a_n) const
			{
				return Vector2(x * a_n, y * a_n);
			}

			void operator/=(const real a_n)
			{
				if (a_n != 0)
				{
					x /= a_n;
					y /= a_n;
				}
			}

			Vector2 operator/(const real a_n) const
			{
				if (a_n > 0)
				{
					return Vector2(x / a_n, y / a_n);
				}
				return *this;
			}

			void operator+=(const Vector2& a_v)
			{
				x += a_v.x;
				y += a_v.y;
			}

			Vector2 operator+(const Vector2& a_v) const
			{
				return Vector2(x + a_v.x, y + a_v.y);
			}

			void operator-=(const Vector2& a_v)
			{
				x -= a_v.x;
				y -= a_v.y;
			}

			Vector2 operator-(const Vector2& a_v) const
			{
				return Vector2(x - a_v.x, y - a_v.y);
			}

			bool operator==(const Vector2& a_v)
			{
				return (x == a_v.x && y == a_v.y);
			}
		};






	}
}

#endif