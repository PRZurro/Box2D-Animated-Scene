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

namespace prz
{
	class Particle;

	class ParticlesManager
	{
	private:

		PBuffer<Particle> particlesPool;

	public:

		ParticlesManager()
		{

		}

		~ParticlesManager()
		{

		}

	};
}


#endif // !PARTICLES_MANAGER_H