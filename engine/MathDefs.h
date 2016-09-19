#ifndef MATH_DEFS_H
#define MATH_DEFS_H

#define F_PI 3.14159265358979f /*float precision*/
//#define PI 3.141592653589793238463 /*double precision*/

#define RAD_TO_DEG 180.0f / F_PI
#define DEG_TO_RAD F_PI / 180.0f

#include <algorithm>

class MathHelper
{
public:
	template<typename T>
	static T CLAMP(const T& n, const T& lower, const T& upper)
	{
		return std::max(lower, std::min(n, upper));
	}
};


#endif