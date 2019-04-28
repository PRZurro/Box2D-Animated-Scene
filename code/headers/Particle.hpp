/**
 * @file Particle.hpp
 * @author Pablo Rodríguez Zurro (przuro@gmail.com)
 * @brief Class that handles a sprite and its components. Should be a child of Entity, no time
 * @version 0.1
 * @date 2019-03-14
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef BOX2D_ANIMATED_SCENE_PARTICLE_H_
#define BOX2D_ANIMATED_SCENE_PARTICLE_H_

#include "Entity.hpp"

#include "internal/declarations/Declarations.hpp"

#include <SFML/Graphics.hpp>

using namespace sf;

namespace prz
{
	/**
	 * @brief Class that handles a sprite and its components
	 * 
	 */
	class Particle
	{
	public:

		/**
		 * @brief Construct a new Particle object by default
		 * 
		 */
		Particle() :
			curTimeOfLife_(.0f),
			sprite_(),
			positionX_(0.f),
			positionY_(0.f),
			id_(-1),
			isActive_(false),
			scale_(1.f)
		{}
		
		/**
		 * @brief Construct a new Particle object
		 * 
		 * @param texture 
		 * @param posX 
		 * @param posY 
		 * @param scale 
		 * @param isActive 
		 */
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

		/**
		 * @brief Update the members 
		 * 
		 * @param deltaTime 
		 */
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

		/**
		 * @brief Render the members
		 * 
		 * @param window 
		 */
		void render(RenderWindow& window)
		{
			if (isActive_)
			{
				window.draw(sprite_);
			}
		}

		/**
		 * @brief Pure virtual method to add extra logic in child implementation
		 * 
		 * @param deltaTime 
		 */
		virtual void auxiliar_update(float deltaTime) = 0;

		/**
		 * @brief reset the members to the input values
		 * 
		 * @param posX 
		 * @param posY 
		 * @param scale 
		 * @param isActive 
		 */
		void reset(float posX, float posY, float scale, bool isActive = true)
		{
			positionX_ = posX;
			positionY_ = posY;
			scale_ = scale;
			isActive_ =	isActive;
			curTimeOfLife_ = 0.f;
		}

	public:
		 /**
		  * @brief Set the active object
		  * 
		  * @param active 
		  */
		void set_active(bool active)
		{
			isActive_ = active;
		}
		 
		/**
		 * @brief Set the sprite texture object
		 * 
		 * @param texture 
		 */
		void set_sprite_texture(const Texture& texture)
		{
			sprite_.setTexture(texture);
		}

		/**
		 * @brief Set the position x object
		 * 
		 * @param positionX 
		 */
		void set_position_x(float positionX)
		{
			positionX = positionX;
		}

		/**
		 * @brief Set the position y object
		 * 
		 * @param positionY 
		 */
		void set_position_y(float positionY)
		{
			positionY_ = positionY;
		}

		/**
		 * @brief Set the position object
		 * 
		 * @param positionX 
		 * @param positionY 
		 */
		void set_position(float positionX, float positionY)
		{
			positionX_ = positionX;
			positionY_ = positionY;
		}

		/**
		 * @brief Set the id object
		 * 
		 * @param id 
		 */
		void set_id(int id)
		{
			id_ = id;
		}

	public:

		/**
		 * @brief get the active state
		 * 
		 * @return true 
		 * @return false 
		 */
		inline bool isActive()
		{
			return isActive_;
		}

		/**
		 * @brief get the position x
		 * 
		 * @return float 
		 */
		inline float positionX()
		{
			return positionX_;
		}

		/**
		 * @brief get the position y
		 * 
		 * @return float 
		 */
		inline float positionY()
		{
			return positionY_;
		}

		/**
		 * @brief get the current time of life
		 * 
		 * @return float 
		 */
		inline float currentTimeOfLife()
		{
			return curTimeOfLife_;
		}

		/**
		 * @brief get the id
		 * 
		 * @return int 
		 */
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