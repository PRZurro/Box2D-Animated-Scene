/**
 * @file ParticleSystem.hpp
 * @author Pablo Rodríguez Zurro (przuro@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-03-14
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef BOX2D_ANIMATED_SCENE_PARTICLE_SYSTEM_H_
#define BOX2D_ANIMATED_SCENE_PARTICLE_SYSTEM_H_

#include "internal/declarations/Declarations.hpp"
#include "Particle.hpp"

namespace prz
{
	class Particle;

	class ParticleSystem
	{
	public:

		ParticleSystem(size_t nParticles, float timeToRefresh)
			:
			nParticles_(nParticles),
			timeToRefresh_(timeToRefresh),
			activeParticles_(nParticles_),
			inactiveParticles_()
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

		PBuffer< Particle>		particles_;
		PBuffer< Particle*>		activeParticles_;
		PBuffer< Particle* >	inactiveParticles_;

	private:

		size_t nParticles_;
		float timeToRefresh_;
	};

}

#endif // !BOX2D_ANIMATED_SCENE_PARTICLE_SYSTEM_H_