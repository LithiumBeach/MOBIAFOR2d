#ifndef PARTICLE_H
#define PARTICLE_H

#include "Transform.h"
#include "CoreTypes.h"

#include <memory>

namespace mob_phys
{
	class Particle
	{
	public:
		typedef mob_core::math::Transform Transform;
		typedef mob_core::math::Vector2 Vector2;
		typedef float real;
		typedef mob_core::types::time_type time_type;

	public:
		Particle(){};
		Particle(Transform a_trans) :	m_trans(a_trans), m_parent(mob_core::math::WORLD_TRANSFORM_PTR),
										m_velocity(Vector2(0)), m_acceleration(Vector2(0)),
										m_force(Vector2(0)), m_mass(1.0f), m_drag(0.0f),
										m_angular_velocity(0.0f), m_angular_acceleration(0.0f), m_angular_drag(0.0f){};

		Particle(Transform a_trans, Transform* a_parent_trans) :	m_trans(a_trans), m_parent(a_parent_trans),
																	m_velocity(Vector2(0)), m_acceleration(Vector2(0)),
																	m_force(Vector2(0)), m_mass(1.0f), m_drag(0.0f),
																	m_angular_velocity(0.0f), m_angular_acceleration(0.0f), m_angular_drag(0.0f){};
	
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
		Vector2 m_mass;
		real m_drag;

		real m_angular_velocity;
		real m_angular_acceleration;
		real m_angular_drag;
	};
}

#endif