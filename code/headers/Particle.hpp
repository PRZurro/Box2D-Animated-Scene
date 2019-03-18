/**
 * @file Particle.hpp
 * @author Pablo Rodríguez Zurro (przuro@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-03-14
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef PARTICLE_H
#define PARTICLE_H

#include "Internal/Declarations/Declarations.hpp"
#include "Entity.hpp"

#include <SFML/Graphics.hpp>

using namespace sf;

namespace prz
{
	class Particle
	{
	public:

		Particle(PString* firstTexturePath, size_t nSprite)
			:
			curTimeOfLife_(.0f)
		{
			Texture texture; 
			texture.loadFromFile(*firstTexturePath);

			set_texture(texture);
		}

		~Particle()
		{

		}
		
	public:

		void update(float deltaTime)
		{
			curTimeOfLife_ += deltaTime;
		}

	public:

		void set_texture(Texture & texture)
		{
			sprite_->setTexture(texture);
		}

	private:

		PShared_ptr<Sprite> sprite_;

		float curTimeOfLife_;

	};
}

#endif // !PARTICLE_H
