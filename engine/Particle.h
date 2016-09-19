#ifndef PARTICLE_H
#define PARTICLE_H

#include "Transform.h"
#include "CoreTypes.h"
#include "Entity.h"
#include "MathDefs.h"

namespace mob_phys
{
	namespace bounds
	{
		const float MIN_MASS = 0.0001f;
		const float MAX_MASS = FLT_MAX;
	}


	class Particle : public Entity
	{
	public:
		typedef mob_core::math::Transform Transform;
		typedef mob_core::math::Vector2 Vector2;
		typedef float real;
		typedef mob_core::types::time_type time_type;

	public:
		enum Integrator
		{
			EULER = 0,
			VERLET,
			RK4
		};

	public:
		//constructor: default parent to world parent
		Particle(Transform a_trans, Integrator a_integrator = Integrator::EULER) 
										:	m_trans(a_trans), m_parent(mob_core::math::WORLD_TRANSFORM_PTR),
											m_velocity(Vector2(0)), m_acceleration(Vector2(0)),
											m_force(Vector2(0)), m_mass(1.0f), m_drag(0.0f),
											m_angular_velocity(0.0f), m_angular_acceleration(0.0f), m_angular_drag(0.0f), m_torque(0.0f)
		{
			//point to an integrator function.
			switch (a_integrator)
			{
			case EULER:
				m_integrator_ptr = &Particle::IntegrateEuler;
				break;
			case VERLET:
				m_integrator_ptr = &Particle::IntegrateVerlet;
				break;
			case RK4:
				m_integrator_ptr = &Particle::IntegrateRK4;
				break;
			default:
				m_integrator_ptr = &Particle::IntegrateEuler;
				break;
			}
			//clamp mass
			MathHelper::CLAMP(m_mass, bounds::MIN_MASS, bounds::MAX_MASS);
		};

		//constructor: custom parent
		Particle(Transform a_trans, Transform* a_parent_trans, Integrator a_integrator = Integrator::EULER)
										:	m_trans(a_trans), m_parent(a_parent_trans), 
											m_velocity(Vector2(0)), m_acceleration(Vector2(0)),
											m_force(Vector2(0)), m_mass(1.0f), m_drag(0.0f),
											m_angular_velocity(0.0f), m_angular_acceleration(0.0f), m_angular_drag(0.0f), m_torque(0.0f)
		{
			//point to an integrator function
			switch (a_integrator)
			{
			case EULER:
				m_integrator_ptr = &Particle::IntegrateEuler;
				break;
			case VERLET:
				m_integrator_ptr = &Particle::IntegrateVerlet;
				break;
			case RK4:
				m_integrator_ptr = &Particle::IntegrateRK4;
				break;
			default:
				m_integrator_ptr = &Particle::IntegrateEuler;
				break;
			}
			//clamp mass
			MathHelper::CLAMP(m_mass, bounds::MIN_MASS, bounds::MAX_MASS);
		};
	
		~Particle();

	public:
		void Integrate(time_type a_deltaTime);

	private:
		//integrator function pointer.
		void (mob_phys::Particle::*m_integrator_ptr)(time_type);

	public:
		//brain cursor put more integrators here
		void IntegrateEuler(time_type a_deltaTime);
		void IntegrateVerlet(time_type a_deltaTime);
		void IntegrateRK4(time_type a_deltaTime);

	private://note: normal-update = aggregate forces, post-update = integrate
		void IntegrateEulerPosition(time_type a_deltaTime);
		void IntegrateEulerRotation(time_type a_deltaTime);

		void IntegrateVerletPosition(time_type a_deltaTime);
		void IntegrateVerletRotation(time_type a_deltaTime);

		void IntegrateRK4Position(time_type a_deltaTime);
		void IntegrateRK4Rotation(time_type a_deltaTime);

	public:
		void AddForce(Vector2 a_force){ m_force += a_force; }


	private:
		Transform m_trans;
		Transform* m_parent;

		Vector2 m_velocity;
		Vector2 m_acceleration;

		Vector2 m_force;
		real m_mass;
		real m_drag;

		real m_angular_velocity;
		real m_angular_acceleration;
		real m_angular_drag;

		real m_torque;
	};
}

#endif