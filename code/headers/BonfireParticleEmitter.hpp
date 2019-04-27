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

#include "Entity.hpp"
#include "ParticleEmitter.hpp"
#include "FireParticle.hpp"
#include "TextureStore.hpp"

#include "internal/Utilities.hpp"

namespace prz
{
	class BonfireParticleEmitter : public ParticleEmitter<FireParticle> 
	{
	public:

		BonfireParticleEmitter
		(
			size_t nParticles,
			float particlesLifeTime,
			size_t nResetedParticles,
			float timeToRefresh,
			float segmentPointAX, 
			float segmentPointAY,
			float segmentPointBX, 
			float segmentPointBY,
			Scene& scene,
			const PString& name,
			float windowHeight
		):
			ParticleEmitter(nParticles, particlesLifeTime, nResetedParticles, timeToRefresh, segmentPointAX, segmentPointAY, segmentPointBX, segmentPointBY, scene, name, windowHeight)
		{
			float boxSize = abs(segmentPointBX - segmentPointAX);
			startTransform_.p = b2Vec2(segmentPointAX_, windowHeight - segmentPointAY_);

			b2Vec2 polygonPoints[4] =
			{
				{0.f, 0.f},
				{0.f, boxSize},
				{boxSize, boxSize},
				{boxSize, 0.f}
			};

			b2BodyDef bodyDef;

			b2PolygonShape bodyShape;
			bodyShape.Set(polygonPoints, 4);

			b2FixtureDef bodyFixture;

			bodyFixture.shape = &bodyShape;
			bodyFixture.density = 1.00f;
			bodyFixture.restitution = 0.75f;
			bodyFixture.friction = 0.50f;

			b2Body* body = add_body(&bodyDef, "body_sensor", b2_kinematicBody);
			add_fixture_to(body, &bodyFixture);

			TextureStore textureStoreIns = TextureStore::instance();

			if (textureStoreIns.is_texture_with_name_loaded("fire_particle.png"))
			{
				for (auto& fireParticle : particles_)
				{
					reset_fire_particle(fireParticle, false);
					fireParticle.set_sprite_texture(*textureStoreIns.get_texture_by_name("fire_particle.png"));
				}
			}
		}

	protected:

		virtual void particle_restablished(FireParticle & fireParticle) override
		{
			reset_fire_particle(fireParticle);
		}

		void reset_fire_particle(FireParticle & fireParticle, bool isActive = true)
		{
			float posX = random<float>(segmentPointAX_, segmentPointBX_);
			float posY = (segmentPointBY_ - segmentPointAY_) / (segmentPointBX_ - segmentPointAX_) * (posX - segmentPointAX_) + segmentPointAY_;
			float scale = random<float>(MIN_SCALE, MAX_SCALE);
			
			fireParticle.reset(posX, posY, scale, isActive);

			fireParticle.custom_reset
			(
				random<float>(MIN_SPEED, MAX_SPEED),
				random<float>(MIN_AMPLITUDE, MAX_AMPLITUDE),
				random<float>(MIN_FREQUENCY, MAX_FREQUENCY),
				random<float>(MIN_PHASE, MAX_PHASE)
			);
		}

	private:

		static constexpr float MIN_SCALE = 0.05f;
		static constexpr float MAX_SCALE = 0.12f;
		static constexpr float MIN_SPEED = -40.f;
		static constexpr float MAX_SPEED = -100.f;
		static constexpr float MIN_AMPLITUDE = 0.2f;
		static constexpr float MAX_AMPLITUDE = 1.0f;
		static constexpr float MIN_FREQUENCY = 0.5f;
		static constexpr float MAX_FREQUENCY = 1.0f;
		static constexpr float MIN_PHASE = 0.2f;
		static constexpr float MAX_PHASE = 0.5f;
	};
}

#endif // !BOX2D_ANIMATED_SCENE_BONFIRE_PARTICLE_SYSTEM_H_