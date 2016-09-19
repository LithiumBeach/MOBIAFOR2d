#include "ParticleSystem.h"

using namespace mob_phys;

void ParticleSystem::AddParticle(Particle* a_particle)
{
	m_particle_map.insert(std::pair<unsigned int, Particle*>(a_particle->GetID(), a_particle));
}

bool ParticleSystem::DestroyParticle(Particle* a_particle)
{
	std::map<unsigned int, Particle*>::iterator iter = m_particle_map.find(a_particle->GetID());

	//if we found a_particle
	if (iter != m_particle_map.end())
	{
		delete iter->second;
		m_particle_map.erase(iter);
		return true;
	}
	//otherwise we did not find a_particle, and we will not delete anything
	return false;
}

void ParticleSystem::Update(time_type a_deltaTime)
{//for now, does nothing.

}

//since our integrators use force-aggregate physics, we want to integrate LAST, after our particles' forces have been summed.
void ParticleSystem::PostUpdate(time_type a_deltaTime)
{
	for (auto iter = m_particle_map.begin(); iter != m_particle_map.end(); ++iter)
	{
		iter->second->Integrate(a_deltaTime);
	}
}