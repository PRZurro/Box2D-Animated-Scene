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

#include "Entity.hpp"

#include <Box2D/Box2D.h>

namespace prz
{
	class Entity;

	class Scene
	{
	public:

		Scene()
		{
			b2BodyDef b2Bodies[3];

			Entity car{physicsWorld_.get(), b2Bodies, b2Bodies + 2, true };
			
		}

		~Scene()
		{

		}
	public:

		void create_level();
		void create_car();
		void create_ball();
		void create_platforms();
		void create_fire();

	public:

		PShared_ptr<b2Body> create_body(const b2BodyDef * bodyDefinition) const
		{
			return PShared_ptr<b2Body>(physicsWorld_->CreateBody(bodyDefinition));
		}

		PShared_ptr<b2Joint> create_joint(const b2JointDef * jointDefinition) const
		{
			return PShared_ptr<b2Joint>(physicsWorld_->CreateJoint(jointDefinition));
		}

	private:

		PShared_ptr< b2World > physicsWorld_;

		PMap<PString, Entity> entities_;
	};
}

#endif // !SCENE_H
