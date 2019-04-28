/**
 * @file Scene.hpp
 * @author Pablo Rodríguez Zurro (przuro@gmail.com)
 * @brief Class to store the entities and manage the Box2D world
 * @version 0.1
 * @date 2019-03-14
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef BOX2D_ANIMATED_SCENE_SCENE_H_
#define BOX2D_ANIMATED_SCENE_SCENE_H_

#include "Entity.hpp"
#include "GameController.hpp"
#include "ContactListener.hpp"

#include "internal/declarations/Declarations.hpp"

#include <Box2D/Box2D.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;

namespace prz
{
	class VehicleEntity;

	/**
	 * @brief Class to store the entities and manage the Box2D world
	 * 
	 */
	class Scene
	{
	public:

		/**
		 * @brief Construct a new Scene object
		 * 
		 * @param posX 
		 * @param posY 
		 * @param windowWidth 
		 * @param windowHeight 
		 */
		Scene(float posX, float posY, float windowWidth, float windowHeight) // CAMBIAR TODOS LOS B2Vec y tipos que encapsulan varias variables
			:
			physicsWorld_(new b2World(b2Vec2(posX, posY))),
			windowWidth_(windowWidth),
			windowHeight_(windowHeight),
			mustReset_(false)
		{}

		/**
		 * @brief Destroy the Scene object
		 * 
		 */
		~Scene()
		{}

	public:

		/**
		 * @brief Update the scene and its members
		 * 
		 * @param deltaTime 
		 */
		void update(float deltaTime);

		/**
		 * @brief render the scene
		 * 
		 * @param window 
		 */
		void render(RenderWindow& window);

	public:

		/**
		 * @brief Create a entity object
		 * 
		 * @param name 
		 * @param posX 
		 * @param posY 
		 * @param angleDegrees 
		 * @param active 
		 * @return PShared_ptr<Entity> 
		 */
		PShared_ptr<Entity> create_entity(const PString& name, float posX, float posY, float angleDegrees, bool active = true)
		{
			return entities_[name] = PShared_ptr<Entity>(new Entity(*this, name, posX, posY , angleDegrees, active));
		}

		/**
		 * @brief add a previous created entity, must be a shared pointer
		 * 
		 * @param entity 
		 * @return PShared_ptr<Entity> 
		 */
		PShared_ptr<Entity> add_entity(PShared_ptr<Entity> entity)
		{
			return entities_[entity->name()] = entity; 
		}

		/**
		 * @brief Create a body object
		 * 
		 * @param bodyDefinition 
		 * @return b2Body* 
		 */
		b2Body* create_body(const b2BodyDef* bodyDefinition) const
		{
			return physicsWorld_->CreateBody(bodyDefinition);
		}

		/**
		 * @brief Create a joint object
		 * 
		 * @param jointDefinition 
		 * @return b2Joint* 
		 */
		b2Joint* create_joint(const b2JointDef* jointDefinition) const
		{
			return physicsWorld_->CreateJoint(jointDefinition);
		}

	public:

		/**
		 * @brief flag to reset in the next tick
		 * 
		 */
		void must_reset()
		{
			mustReset_ = true;
		}

	public:

		/**
		 * @brief Set the contact listener to the physics world of Box2D
		 * 
		 * @param contactListener 
		 */
		void set_contact_listener(b2ContactListener* contactListener)
		{
			physicsWorld_->SetContactListener(contactListener);
		}

	protected:

		/**
		 * @brief auxiliar update for child implementation
		 * 
		 * @param deltaTime 
		 */
		virtual void auxiliar_update(float deltaTime)
		{}

	protected:

		/**
		 * @brief reset the scene and its members
		 * 
		 */
		void reset()
		{
			for (auto& entity : entities_)
			{
				entity.second->reset();
			}
		}

	protected:

		PShared_ptr< b2World > physicsWorld_;

		PMap< PString, PShared_ptr<Entity> > entities_;

	protected:

		float windowHeight_;
		float windowWidth_;

	protected:
		
		bool mustReset_;
	};
}
#endif // !BOX2D_ANIMATED_SCENE_SCENE_H_
