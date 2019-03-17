/**
 * @file Entity.hpp
 * @author Pablo Rodríguez Zurro (przuro@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-03-14
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Internal/Declarations/Declarations.hpp"
#include "Box2D/Box2D.h"

namespace prz
{
	class Entity
	{
	private:

		PBuffer< PSptr< b2Body > >	bodies;
		PBuffer< PSptr< b2Joint > > joints;

		bool isActive;

	public:

		Entity()
		{

		}

		Entity(b2BodyDef * firstBodyDef, b2BodyDef * lastBodyDef)
		{

		}

		~Entity()
		{

		}

	public:

		void update(float deltaTime)
		{

		}

	public:

		void set_active(bool state = true)
		{
			isActive = state; 
		}
	};
}

#endif // !GAMEOBJECT_H
