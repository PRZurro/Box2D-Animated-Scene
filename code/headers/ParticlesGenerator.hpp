/**
 * @file ParticlesGenerator.hpp
 * @author Pablo Rodríguez Zurro (przuro@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-03-14
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef BOX2D_ANIMATED_SCENE_PARTICLES_MANAGER_H_
#define BOX2D_ANIMATED_SCENE_PARTICLES_MANAGER_H_

#include "Internal/Declarations/Declarations.hpp"
#include "Particle.hpp"

namespace prz
{
	class Particle;

	class ParticlesGenerator
	{
	public:

		ParticlesGenerator(size_t nParticles, float timeToRefresh)
			:
			nParticles_(nParticles),
			timeToRefresh_(timeToRefresh),
			activeParticles_(nParticles_),
			inactiveParticles_()
		{}

		~ParticlesGenerator()
		{}

	public:

		void update(float deltaTime)
		{
			for (auto & particle : activeParticles_)
			{
				particle->update(deltaTime);
			}
		}

	private:

		PBuffer< PShared_ptr<Particle> > activeParticles_;
		PBuffer< PShared_ptr<Particle> > inactiveParticles_;

	private:

		size_t nParticles_;
		float timeToRefresh_;
	};

}

#endif // !BOX2D_ANIMATED_SCENE_PARTICLES_MANAGER_H_