/**
 * @file ParticleEmitter.hpp
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

#include "Entity.hpp"
#include "Particle.hpp"

#include "internal/declarations/Declarations.hpp"
#include "internal/Utilities.hpp"

namespace prz
{
	template<class P>
	class ParticleEmitter : public Entity
	{
	public:

		ParticleEmitter
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
		) :
			Entity(scene, name, segmentPointAX_, segmentPointAY_),
			nParticles_(nParticles),
			particles_(),
			activeParticles_(),
			inactiveParticles_(),
			particlesLifeTime_(particlesLifeTime),
			nResetedParticles_(nResetedParticles),
			resetFrequency_(timeToRefresh),
			segmentPointAX_(segmentPointAX),
			segmentPointAY_(windowHeight - segmentPointAY),
			segmentPointBX_(segmentPointBX),
			segmentPointBY_(windowHeight - segmentPointBY),
			timer_(0.f)
		{
			set_collision_filter(BALL);
			set_polygons_color(Color(145, 247, 44, 60));
			set_type(PARTICLE_EMITTER);

			particles_.reserve(nParticles_);

			for (int i = 0; i < nParticles_; ++i)
			{
				particles_.push_back(P());
				P* particle = &particles_[i];
				inactiveParticles_[i] = static_cast<Particle*>(particle);
				inactiveParticles_[i]->set_id(i);
			}
		}

	protected:

		virtual void auxiliar_update(float deltaTime) final 
		{
			timer_ += deltaTime;

			// Re-establishing inactive particles 
			if (timer_ >= resetFrequency_)
			{
				size_t i = 0;

				for(auto& pair : inactiveParticles_)
				{
					Particle* particle = pair.second;
					activeParticles_[particle->id()] = particle;
					inactiveParticles_.erase(inactiveParticles_.find(particle->id()));
					particle_restablished(particles_[particle->id()]);

					i++;
					if (i > nResetedParticles_)
						break;
				}

				//UNKNOWN ERROR
				/*auto iter = inactiveParticles_.begin(), end = inactiveParticles_.end();
				for (size_t i = 0; iter != end && i < nResetedParticles_; ++iter, ++i)
				{
					Particle* particle = iter->second;
					activeParticles_[particle->id()] = particle;
					inactiveParticles_.erase(inactiveParticles_.find(particle->id()));
					particle_restablished(particles_[particle->id()]);
				}
*/
				timer_ = 0.f;
			}

			for (auto& pair : activeParticles_)
			{
				Particle* particle = pair.second;

				if (particle->currentTimeOfLife() < particlesLifeTime_)
				{
					particle->update(deltaTime);
				}
				else
				{
					particle->set_active(false);
					inactiveParticles_[particle->id()] = particle;
					activeParticles_.erase(activeParticles_.find(particle->id()));
				}
			}

			emitter_auxiliar_update(deltaTime);
		}

		virtual void auxiliar_render(RenderWindow& window) final
		{
			for (Particle& particle : particles_)
			{
				particle.render(window);
			}
		}

	protected:


		virtual void emitter_auxiliar_update(float deltaTime){}
		virtual void emitter_auxiliar_render(RenderWindow& window){}
		virtual void particle_restablished(P& particle){}

	protected:

		PBuffer< P >				particles_;
		PMap< int, Particle* >		activeParticles_; // 4 bytes + 1 byte, the value does nothing
		PMap< int, Particle* >		inactiveParticles_; // 4 bytes + 1 byte, the value does nothing

	protected:

		size_t nParticles_;
		size_t nResetedParticles_;
		float particlesLifeTime_;
		float resetFrequency_; // In seconds
		float timer_;

	protected:

		float segmentPointAX_;
		float segmentPointAY_;

		float segmentPointBX_;
		float segmentPointBY_;
	};
}
#endif // !BOX2D_ANIMATED_SCENE_PARTICLE_SYSTEM_H_