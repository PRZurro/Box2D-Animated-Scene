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
	class Particle : public Entity
	{
	private:

		float m_CurTimeOfLife;
		float m_MaxTimeOfLife;

		PSptr<Sprite> sprite;

	public:

		Particle(PString* firstTexturePath, size_t nSprites, float maxTimeOfLife)
			:
			m_CurTimeOfLife(.0f),
			m_MaxTimeOfLife(maxTimeOfLife)
		{
				shapes.push_back(PSptr<Texture>(new Texture()));
				shapes.back()-
		}

		~Particle()
		{

		}
		
	public:

		void update(float deltaTime)
		{

		}

	public:

		void setTexture(Texture & texture)
		{
			sprite->setTexture(texture);
		}

	public:

		curTi
	};
}

#endif // !PARTICLE_H
