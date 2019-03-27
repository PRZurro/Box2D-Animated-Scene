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
		using ParticleEmitter<FireParticle>::exists_texture_with_name;

	public:

		BonfireParticleEmitter
		(
			size_t nParticles,
			float particlesLifeTime,
			size_t nResetedParticles,
			float timeToRefresh,
			PBuffer<PString>& texturePaths,
			float segmentPointAX, float segmentPointAY,
			float segmentPointBX, float segmentPointBY
		)
			:
			ParticleEmitter(nParticles, particlesLifeTime, nResetedParticles, timeToRefresh, texturePaths, segmentPointAX, segmentPointAY, segmentPointBX, segmentPointBY)
		{
			/*if (exists_texture_with_name("fire.png"))
			{
				for (auto & fireParticle : particles_)
				{
					reset_fire_particle(fireParticle);
					fireParticle.set_sprite_texture(*texturesByName_["fire.png"]);
				}
			}*/
		}

	protected:

		virtual void auxiliar_update(float deltaTime) override;


		virtual void particle_restablished(FireParticle & fireParticle)
		{
			reset_fire_particle(fireParticle);
		}

		void reset_fire_particle(FireParticle& fireParticle)
		{
			float posX = random<float>(segmentPointAX, segmentPointBX);
			float posY = (segmentPointBY - segmentPointAY) / (segmentPointBX - segmentPointAX) * (posX - segmentPointAX) + segmentPointAY;

			fireParticle.reset(posX, posY, true);

			fireParticle.custom_reset
			(
				random<float>(MIN_SPEED, MAX_SPEED, true),
				random<float>(MIN_AMPLITUDE, MAX_AMPLITUDE),
				random<float>(MIN_FREQUENCY, MAX_FREQUENCY),
				random<float>(MIN_PHASE, MAX_PHASE)
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