#include "Particle.h"

using namespace mob_phys;

Particle::~Particle()
{
}

void Particle::Integrate(time_type a_deltaTime)
{
	(this->*m_integrator_ptr)(a_deltaTime);
}


void Particle::IntegrateEuler(time_type a_deltaTime)
{
	IntegrateEulerPosition(a_deltaTime);
	IntegrateEulerRotation(a_deltaTime);
}

void Particle::IntegrateEulerPosition(time_type a_deltaTime)
{

}

void Particle::IntegrateEulerRotation(time_type a_deltaTime)
{

}


void Particle::IntegrateVerlet(time_type a_deltaTime)
{
	IntegrateVerletPosition(a_deltaTime);
	IntegrateVerletRotation(a_deltaTime);
}

void Particle::IntegrateVerletPosition(time_type a_deltaTime)
{

}

void Particle::IntegrateVerletRotation(time_type a_deltaTime)
{

}


void Particle::IntegrateRK4(time_type a_deltaTime)
{
	IntegrateRK4Position(a_deltaTime);
	IntegrateRK4Rotation(a_deltaTime);
}

void Particle::IntegrateRK4Position(time_type a_deltaTime)
{

}

void Particle::IntegrateRK4Rotation(time_type a_deltaTime)
{

}