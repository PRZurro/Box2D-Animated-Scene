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

		Scene(float posX, float posY, float windowWidth, float windowHeight) // CAMBIAR TODOS LOS B2Vec y tipos que encapsulan varias variables
			:
			physicsWorld_(new b2World(b2Vec2(posX, posY))),
			windowWidth_(windowWidth),
			windowHeight_(windowHeight)
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

		PShared_ptr<Entity> add_entity(PShared_ptr<Entity> entity)
		{
			return entities_[entity->name()] = entity; 
		}

		void add_vehicle(VehicleEntity* vehicleEntity)
		{
			vehicles_.push_back(vehicleEntity);
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

	protected:

		PShared_ptr< b2World > physicsWorld_;

		PMap< PString, PShared_ptr<Entity> > entities_;
		PBuffer< VehicleEntity*> vehicles_;

	protected:

		float windowHeight_;
		float windowWidth_;
	};
}
#endif // !BOX2D_ANIMATED_SCENE_SCENE_H_