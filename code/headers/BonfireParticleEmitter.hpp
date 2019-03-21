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
	class FireParticle;

	class BonfireParticleEmitter : public ParticleEmitter<FireParticle>
	{
		using ParticleEmitter<FireParticle>::exists_texture_with_name;

	public:

		BonfireParticleEmitter
		(
			size_t nParticles,
			float timeToRefresh,
			PBuffer<PString>& texturePaths,
			float segmentPointAX, float segmentPointAY,
			float segmentPointBX, float segmentPointBY
		)
			:
			ParticleEmitter<FireParticle>(nParticles, timeToRefresh, texturePaths, segmentPointAX, segmentPointAY, segmentPointBX, segmentPointBY)
		{
			if (exists_texture_with_name("fire.png"))
			{
				for (auto & fireParticle : particles_)
				{


					reset(fireParticle, texturesByName_["fire.png"]);
					//Texture texture;



					//FireParticle fireParticleTemp
					//(

					//	0.f, //Ecuacion de la recta random
					//	0.f, //Ecuacion de la recta random
					//	
					//);
				}
			}
		}

	protected:

		virtual void auxiliar_update(float deltaTime) override
		{
			for (FireParticle & fireParticle : particles_)
			{
				if (fireParticle.isActive())
				{
					if(fireParticle)
				}
			}
		}

		void reset(FireParticle& fireParticle, const Texture& texture)
		{
			float posX = random(segmentPointAX, segmentPointBX);
			float posY = (segmentPointBY - segmentPointAY) / (segmentPointBX - segmentPointAX) * (posX - segmentPointAX) + segmentPointAY;

			fireParticle.reset
			(
				posX,
				posY,
				true
			);

			fireParticle.custom_reset
			(
				random(MIN_SPEED, MAX_SPEED, true),
				random(MIN_AMPLITUDE, MAX_AMPLITUDE),
				random(MIN_FREQUENCY, MAX_FREQUENCY),
				random(MIN_PHASE, MAX_PHASE)
			);
		}

		
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