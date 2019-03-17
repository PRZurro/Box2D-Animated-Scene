/**
 * @file GameObject.hpp
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
	class GameObject
	{
	private:

		PBuffer< PSptr< b2Body > >	bodies;
		PBuffer< PSptr< b2Joint > > joints;

	public:

		GameObject()
		{

		}

		GameObject(b2BodyDef * firstBodyDef, b2BodyDef * lastBodyDef)
		{

		}

		~GameObject()
		{

		}


	
	};
}

#endif // !GAMEOBJECT_H
