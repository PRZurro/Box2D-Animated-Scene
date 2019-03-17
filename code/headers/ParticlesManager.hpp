/**
 * @file ParticlesManager.hpp
 * @author Pablo Rodríguez Zurro (przuro@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-03-14
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef PARTICLES_MANAGER_H
#define PARTICLES_MANAGER_H

#include "Internal/Declarations/Declarations.hpp"
#include "Particle.hpp"

namespace prz
{
	class Particle;

	class ParticlesManager
	{
	private:

		PBuffer< PSptr < Particle > > activeParticles;
		PBuffer< PSptr < Particle > > inactiveParticles;

	private:

		size_t maxParticlesN;

	public:

		ParticlesManager()
		{

		}

		~ParticlesManager()
		{

		}


	public:

		void update(float deltaTime)
		{
			for (auto & particle : activeParticles)
			{
				particle->update(deltaTime);
			}
		}
	};
}


#endif // !PARTICLES_MANAGER_H