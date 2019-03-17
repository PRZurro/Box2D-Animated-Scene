/**
 * @file Scene.hpp
 * @author Pablo Rodríguez Zurro (przuro@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-03-14
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef SCENE_H
#define SCENE_H

#include "Internal/Declarations/Declarations.hpp"
#include "Box2D/Box2D.h"

namespace prz
{
	class Entity;

	class Scene
	{
	private:
		
		PSptr< b2World > physicsWorld;

		PMap<PString, Entity> gameObjects;

	public:

		Scene()
		{

		}

		~Scene()
		{

		}
	};
}

#endif // !SCENE_H
