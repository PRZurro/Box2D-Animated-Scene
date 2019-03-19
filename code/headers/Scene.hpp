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

#ifndef BOX2D_ANIMATED_SCENE_SCENE_H_
#define BOX2D_ANIMATED_SCENE_SCENE_H_

#include "internal/declarations/Declarations.hpp"

#include "Entity.hpp"

#include <Box2D/Box2D.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;

namespace prz
{
	class Entity;

	class Scene
	{
	public:

		Scene(const b2Vec2& worldPosition)
			:
			physicsWorld_( new b2World(worldPosition))
		{
		}

		~Scene()
		{

		}

	public:

		void render(RenderWindow& window);

	public:

		void create_level();
		void create_car();
		void create_ball();
		void create_platforms();
		void create_fire();

	public:

		PShared_ptr<Entity> create_entity(const PString& name, bool active)
		{
			return entities_[name] = PShared_ptr<Entity>(new Entity(*this, name, active));
		}

		PShared_ptr<b2Body> create_body(const b2BodyDef* bodyDefinition) const
		{
			return PShared_ptr<b2Body>(physicsWorld_->CreateBody(bodyDefinition));
		}

		PShared_ptr<b2Joint> create_joint(const b2JointDef* jointDefinition) const
		{
			return PShared_ptr<b2Joint>(physicsWorld_->CreateJoint(jointDefinition));
		}

	private:

		PShared_ptr< b2World > physicsWorld_;

		PMap< PString, PShared_ptr<Entity> > entities_;
	};
}

#endif // !BOX2D_ANIMATED_SCENE_SCENE_H_
