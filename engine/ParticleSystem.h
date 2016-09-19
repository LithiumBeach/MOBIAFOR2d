#ifndef PARTICLE_SYSTEM_H
#define PARTICLE_SYSTEM_H

#include "Particle.h"

#include <map>

namespace mob_phys
{

	class ParticleSystem
	{
	public:
		typedef Particle::Transform Transform;
		typedef Particle::Vector2 Vector2;
		typedef Particle::real real;
		typedef Particle::time_type time_type;

	public:
		ParticleSystem();
		~ParticleSystem();
		
	private:
		std::map<unsigned int, Particle*> m_particle_map;

	public:
		void AddParticle(Particle* a_particle);
		bool DestroyParticle(Particle* a_particle);

	public:
		void Update(time_type a_deltaTime);
		void PostUpdate(time_type a_deltaTime);

	};

}

#endif