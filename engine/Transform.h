#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "Vector2.h"
#include "MathDefs.h"

namespace mob_core {
	namespace math {


		class Transform
		{
		public:
			typedef float radians;
			typedef float real;

		public:
			Transform() : position(Vector2(0)), rotation(0), scale(Vector2(1)){};

			//a more effective way to set properties would be nice. ->scale(1, 1)->rotation(45)
			Transform(Vector2 a_pos) : position(a_pos), rotation(0), scale(Vector2(1)){};
			Transform(Vector2 a_pos, radians a_rot) : position(a_pos), rotation(a_rot), scale(Vector2(1)){};
			Transform(Vector2 a_pos, radians a_rot, Vector2 a_scale) : position(a_pos), rotation(a_rot), scale(Vector2(a_scale)){};

		public:
			Vector2 position;
			radians rotation;
			Vector2 scale;

			real GetDegrees(){ return RAD_TO_DEG * rotation; }
			void SetDegrees(real a_deg){ rotation = DEG_TO_RAD * a_deg; }

		public:
			void LookAt(Vector2 a_point);


		};


		static Transform WORLD_TRANSFORM = Transform();
		static Transform* WORLD_TRANSFORM_PTR = &WORLD_TRANSFORM;
	}
}

#endif