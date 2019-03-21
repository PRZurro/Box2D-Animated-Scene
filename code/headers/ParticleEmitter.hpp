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

#include "internal/declarations/Declarations.hpp"
#include "internal/Utilities.hpp"

#include "Particle.hpp"

namespace prz
{
	template<class P>
	class ParticleEmitter
	{
	public:

		ParticleEmitter
		(
			size_t nParticles,
			float timeToRefresh,
			PBuffer<PString>& texturePaths,
			float segmentPointAX, float segmentPointAY,
			float segmentPointBX, float segmentPointBY
		)
			:
			nParticles_(nParticles),
			timeToRefresh_(timeToRefresh),
			particles_(nParticles),
			activeParticles_(nParticles_),
			inactiveParticles_()
		{
			for (PString & path : texturePaths)
			{
				Texture texture;
				texture.loadFromFile(path);
				textures_[path] = texture;
				texturesByName_[split_file_name(path)] = &textures_[path];
			}
		}

	public:

		void update(float deltaTime)
		{
			for (auto & particle : activeParticles_)
			{
				particle->update(deltaTime);
			}
			
			auxiliar_update(deltaTime);

			// Re establish dead particles 
		}

	protected:

		bool exists_texture(const PString& texturePath) const
		{
			if (textures_.find(texturePath) != textures_.end())
				return true;

			return false;
		}

		bool exists_texture_with_name(const PString& textureName) const
		{
			if(texturesByName_.find(textureName) != texturesByName_.end())
				return true

			return false;
		}

	protected:

		virtual void auxiliar_update(float deltaTime) = 0;

	protected:

		PBuffer< P >			particles_;
		PBuffer< Particle*>		activeParticles_;
		PBuffer< Particle* >	inactiveParticles_;

		PMap< PString, Texture >     textures_;
		PMap< PString, Texture&>	 texturesByName_;

	protected:

		size_t nParticles_;
		float timeToRefresh_;

	protected:

		float segmentPointAX;
		float segmentPointAY;

		float segmentPointBX;
		float segmentPointBY;
		
	};
}
#endif // !BOX2D_ANIMATED_SCENE_PARTICLE_SYSTEM_H_