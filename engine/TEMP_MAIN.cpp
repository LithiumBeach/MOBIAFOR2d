#include <stdio.h>
#include <stdlib.h>

#include "Vector2.h"
#include "Transform.h"
#include "Particle.h"
#include "MathDefs.h"

#include <memory>

typedef mob_core::math::Vector2 Vector2;
typedef mob_core::math::Transform Transform;
typedef mob_phys::Particle Particle;

void main()
{
	//Vector2 x;
	//Vector2 b(3, -9);
	//x -= b;
	//printf("%f, %f", x.x, x.y);

	//Transform t(Vector2(-4, -32), 0, 1);
	//t.LookAt(Vector2(0, 0));
	//printf("%f", t.GetDegrees());
	
	//Particle p = new Particle(Transform());
	Transform trans(Vector2(0, 0), DEG_TO_RAD * 90.0f);
	std::shared_ptr<Particle> sp_particle(new Particle(trans));

	//printf("%f, %f", sp_particle->GetTEMP());
	
	//printf("%f", mob_core::math::WORLD_TRANSFORM.scale.y);
	
	system("PAUSE");
}