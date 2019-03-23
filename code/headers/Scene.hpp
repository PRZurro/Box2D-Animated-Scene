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
#include "GameController.hpp"
#include "ContactListener.hpp"
#include "InputListener.hpp"

#include <Box2D/Box2D.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

//#include <type_traits>

using namespace sf;

namespace prz
{
	class VehicleEntity;

	class Scene
	{
	public:

		Scene(float posX, float posY, float worldWidth, float worldHeight) // CAMBIAR TODOS LOS B2Vec y tipos que encapsulan varias variables
			:
			physicsWorld_(new b2World(b2Vec2(posX, posY))),
			worldWidth_(worldWidth),
			worldHeight_(worldHeight)
		{}

		~Scene()
		{}

	public:

		virtual void update(float deltaTime);

		void render(RenderWindow& window);

	public:

		PShared_ptr<Entity> create_entity(const PString& name, float posX, float posY, float angleDegrees, bool active = true)
		{
			return entities_[name] = PShared_ptr<Entity>(new Entity(*this, name, posX, posY , angleDegrees, active));
		}

		//PShared_ptr<Entity> add_entity(const Entity& entity)
		//{
		//	// Copy the values of input entity to a new one, because it's provenience is unknown
		//	return entities_[entity.name()] = PShared_ptr<Entity>(new Entity(entity));
		//}

		template<class C>
		PShared_ptr<Entity> add_entity(const C& entity)
		{
			if (std::is_base_of<Entity, C>::value || std::is_same<Entity, C>::value)
			{
				return entities_[entity.name()] = PShared_ptr<Entity>(new C(entity));
			}

			return PShared_ptr<Entity>();
		}

		b2Body* create_body(const b2BodyDef* bodyDefinition) const
		{
			return physicsWorld_->CreateBody(bodyDefinition);
		}

		b2Joint* create_joint(const b2JointDef* jointDefinition) const
		{
			return physicsWorld_->CreateJoint(jointDefinition);
		}

	public:

		void set_contact_listener(b2ContactListener* contactListener)
		{
			physicsWorld_->SetContactListener(contactListener);
		}

	public:

		InputListener& inputListener()
		{
			return inputListener_;
		}

	protected:

		PShared_ptr< b2World > physicsWorld_;

		PMap< PString, PShared_ptr<Entity> > entities_;
		PBuffer< VehicleEntity*> vehicles_;

	protected:

		float worldHeight_;
		float worldWidth_;

	protected:

		InputListener inputListener_;
	};
}

#endif // !BOX2D_ANIMATED_SCENE_SCENE_H_