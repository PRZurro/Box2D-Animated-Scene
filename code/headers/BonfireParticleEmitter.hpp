/**
 * @file BonfireParticleSystem.hpp
 * @author Pablo Rodríguez Zurro (przuro@gmail.com)
 * @brief
 * @version 0.1
 * @date 2019-03-19
 *
 * @copyright Copyright (c) 2019
 *
 */

#ifndef BOX2D_ANIMATED_SCENE_BONFIRE_PARTICLE_SYSTEM_H_
#define BOX2D_ANIMATED_SCENE_BONFIRE_PARTICLE_SYSTEM_H_

#include "internal/Utilities.hpp"

#include "ParticleEmitter.hpp"
#include "FireParticle.hpp"

namespace prz
{
	class BonfireParticleEmitter : public ParticleEmitter<FireParticle>
	{
	public:

		BonfireParticleEmitter(size_t nParticles, float timeToRefresh)
			:
			ParticleEmitter<FireParticle>(nParticles, timeToRefresh)
		{
			for (size_t i = 0; i < nParticles; ++i)
			{
				//Texture texture;

				FireParticle & fireParticleTemp = *particles_[i].get();

				FireParticle fireParticleTemp
				(
					texture,
					0.f, //Ecuacion de la recta random
					0.f, //Ecuacion de la recta random
					random(MIN_SPEED, MAX_SPEED, true),
					random(MIN_AMPLITUDE, MAX_AMPLITUDE),
					random(MIN_FREQUENCY, MAX_FREQUENCY),
					random(MIN_PHASE, MAX_PHASE)
				);
			}
		}

	protected:

	private:

		static constexpr float MIN_SPEED = 0.5f;
		static constexpr float MAX_SPEED = 5.0f;
		static constexpr float MIN_AMPLITUDE = 0.5f;
		static constexpr float MAX_AMPLITUDE = 5.0f;
		static constexpr float MIN_FREQUENCY = 0.5f;
		static constexpr float MAX_FREQUENCY = 5.0f;
		static constexpr float MIN_PHASE = 0.5f;
		static constexpr float MAX_PHASE = 5.0f;
	};
}

#endif // !BOX2D_ANIMATED_SCENE_BONFIRE_PARTICLE_SYSTEM_H_