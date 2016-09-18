#include "Particle.h"

using namespace mob_phys;

void Particle::Integrate(time_type a_deltaTime)
{//okay: http://stackoverflow.com/questions/6913221/c-error-c2064-for-function-pointer-in-c-template
	(this->*m_integrator_ptr)(a_deltaTime);
}


void Particle::IntegrateEuler(time_type a_deltaTime)
{
	printf("euler");
}

void Particle::IntegrateEulerPosition(time_type a_deltaTime)
{

}

void Particle::IntegrateEulerRotation(time_type a_deltaTime)
{

}


void Particle::IntegrateVerlet(time_type a_deltaTime)
{
	printf("verlet");
}

void Particle::IntegrateVerletPosition(time_type a_deltaTime)
{

}

void Particle::IntegrateVerletRotation(time_type a_deltaTime)
{

}


void Particle::IntegrateRK4(time_type a_deltaTime)
{
	printf("rk4");
}

void Particle::IntegrateRK4Position(time_type a_deltaTime)
{

}

void Particle::IntegrateRK4Rotation(time_type a_deltaTime)
{

}