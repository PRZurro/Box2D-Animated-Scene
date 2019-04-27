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

#ifndef BOX2D_ANIMATED_SCENE_PARTICLE_H_
#define BOX2D_ANIMATED_SCENE_PARTICLE_H_

#include "internal/declarations/Declarations.hpp"
#include "Entity.hpp"

#include <SFML/Graphics.hpp>

using namespace sf;

namespace prz
{
	class Particle
	{
	public:

		Particle() :
			curTimeOfLife_(.0f),
			sprite_(),
			positionX_(0.f),
			positionY_(0.f),
			id_(-1),
			isActive_(false),
			scale_(1.f)
		{}

		Particle(const Texture& texture, float posX, float posY, float scale = 1.f, bool isActive = false) :
			curTimeOfLife_(.0f),
			sprite_(texture),
			positionX_(posX),
			positionY_(posY),
			id_(-1),
			scale_(scale),
			isActive_(isActive)
		{}
		
	public:

		void update(float deltaTime)
		{
			if (isActive_)
			{
				curTimeOfLife_ += deltaTime;
				
				sprite_.setPosition(positionX_, positionY_);
				sprite_.setScale({ scale_, scale_ });

				auxiliar_update(deltaTime);
			}
		}

		void render(RenderWindow& window)
		{
			if (isActive_)
			{
				window.draw(sprite_);
			}
		}

		virtual void auxiliar_update(float deltaTime) = 0;

		void reset(float posX, float posY, float scale, bool isActive = true)
		{
			positionX_ = posX;
			positionY_ = posY;
			scale_ = scale;
			isActive_ =	isActive;
			curTimeOfLife_ = 0.f;
		}

	public:

		void set_active(bool active)
		{
			isActive_ = active;
		}

		void set_sprite_texture(const Texture& texture)
		{
			sprite_.setTexture(texture);
		}

		void set_position_x(float positionX)
		{
			positionX = positionX;
		}

		void set_position_y(float positionY)
		{
			positionY_ = positionY;
		}

		void set_position(float positionX, float positionY)
		{
			positionX_ = positionX;
			positionY_ = positionY;
		}

		void set_id(int id)
		{
			id_ = id;
		}

	public:

		inline bool isActive()
		{
			return isActive_;
		}

		inline float positionX()
		{
			return positionX_;
		}

		inline float positionY()
		{
			return positionY_;
		}

		inline float currentTimeOfLife()
		{
			return curTimeOfLife_;
		}

		inline int id()
		{
			return id_;
		}

	protected:

		Sprite sprite_;

		float curTimeOfLife_;
		bool isActive_;
		 
	protected:

		float positionX_;
		float positionY_;

		float scale_;

	protected:

		int id_;
	};
}

#endif // !BOX2D_ANIMATED_SCENE_PARTICLE_H_