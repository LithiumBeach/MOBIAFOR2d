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
	//printf("euler");
}

void Particle::IntegrateEulerPosition(time_type a_deltaTime)
{

}

void Particle::IntegrateEulerRotation(time_type a_deltaTime)
{

}


void Particle::IntegrateVerlet(time_type a_deltaTime)
{
	//printf("verlet");
}

void Particle::IntegrateVerletPosition(time_type a_deltaTime)
{

}

void Particle::IntegrateVerletRotation(time_type a_deltaTime)
{

}


void Particle::IntegrateRK4(time_type a_deltaTime)
{
	//printf("rk4");
}

void Particle::IntegrateRK4Position(time_type a_deltaTime)
{

}

void Particle::IntegrateRK4Rotation(time_type a_deltaTime)
{

}