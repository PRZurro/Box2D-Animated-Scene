#include "ParticleEmitter.hpp"

//namespace prz
//{
//	template<class P>
//	ParticleEmitter<P>::ParticleEmitter(size_t nParticles, float particlesLifeTime, size_t nResetedParticles, float timeToRefresh, PBuffer<PString>& texturePaths, float segmentPointAX, float segmentPointAY, float segmentPointBX, float segmentPointBY)
//		:
//		nParticles_(nParticles),
//		particlesLifeTime_(particlesLifeTime),
//		nResetedParticles_(nResetedParticles),
//		resetFrequency_(timeToRefresh),
//		timer_(0.f),
//		particles_(nParticles),
//		activeParticles_(),
//		inactiveParticles_()
//	{
//		for (PString & path : texturePaths)
//		{
//			Texture texture;
//			texture.loadFromFile(path);
//			textures_[path] = texture;
//			texturesByName_[split_file_name(path)] = &textures_[path];
//		}
//
//		for (size_t i = 0; i < nParticles; ++i)
//		{
//			particles_[i].set_id(i);
//			inactiveParticles_[i] = &particles_[i];
//		}
//	}
//
//	template<class P>
//	void ParticleEmitter<P>::update(float deltaTime)
//	{
//		// Re-establishing inactive particles 
//		if (timer_ >= resetFrequency_)
//		{
//			size_t i = 0;
//
//			auto iter = inactiveParticles_.begin(), end = inactiveParticles_.end();
//			for (size_t i = 0; iter != end && i < nResetedParticles_; ++iter, ++i)
//			{
//				P* particle = iter->second;
//				activeParticles_.push_back(particle);
//				inactiveParticles_.erase(inactiveParticles_.find(particle->id()));
//				particle_restablished(particle);
//			}
//
//			timer_ = 0.f;
//		}
//
//		for (auto& pair : activeParticles_)
//		{
//			P* particle = pair->second;
//
//			if (particle->currentTimeOfLife() < particlesLifeTime_)
//			{
//				particle->update(deltaTime);
//			}
//			else
//			{
//				particle.set_active(false);
//				inactiveParticles_[particle->id()] = particle;
//				activeParticles_.erase(activeParticles_.find(particle->id()));
//			}
//		}
//
//		auxiliar_update(deltaTime);
//	}
//}