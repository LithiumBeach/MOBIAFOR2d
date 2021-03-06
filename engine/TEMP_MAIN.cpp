#include <stdio.h>
#include <stdlib.h>

#include "Vector2.h"
#include "Transform.h"
#include "MathDefs.h"
#include "ParticleSystem.h"

#include <memory>

typedef mob_core::math::Vector2 Vector2;
typedef mob_core::math::Transform Transform;
typedef mob_phys::Particle Particle;
typedef mob_phys::Entity Entity;

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
	Transform trans(Vector2(0), DEG_TO_RAD * 90.0f);
	//std::shared_ptr<Particle> sp_particle(new Particle(trans));

	//printf("%f, %f", sp_particle->GetTEMP());
	
	//printf("%f", mob_core::math::WORLD_TRANSFORM.scale.y);

	//Particle tmpe(trans, mob_phys::Particle::Integrator::EULER);
	//tmpe.Integrate(1.0f);
	//Particle tmpv(trans, mob_phys::Particle::Integrator::VERLET);
	//tmpv.Integrate(1.0f);
	//Particle tmpr(trans, mob_phys::Particle::Integrator::RK4);
	//tmpr.Integrate(1.0f);

	//Particle* a = new Particle(Transform());
	//Particle b(trans);
	//Entity x;
	//Particle* c = new Particle(trans);
	
	//printf("%d\n", a->GetID());
	//printf("%d\n", b.GetID());
	//printf("%d\n", x.GetID());
	
	//printf("%f\n", MathHelper::CLAMP(-5.0f, -2.0f, -490.0f));

	
	system("PAUSE");
}