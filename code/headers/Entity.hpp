/**
 * @file Entity.hpp
 * @author Pablo Rodríguez Zurro (przuro@gmail.com)
 * @brief Core class to store and handle Box2D elements. Represents a GameObject.    
 * @version 0.1
 * @date 2019-03-14
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef BOX2D_ANIMATED_SCENE_ENTITY_H_
#define BOX2D_ANIMATED_SCENE_ENTITY_H_

#include "internal/declarations/Declarations.hpp"

#include <Box2D/Box2D.h>
#include <SFML/Window.hpp>

namespace prz
{
	class Scene;

	class Entity
	{
	public:

		/**
		 * @brief Construct a new Entity object
		 * 
		 * @param scene 
		 * @param name 
		 * @param posX 
		 * @param posY 
		 * @param angleDegrees 
		 * @param active 
		 * @param type 
		 * @param maskBits 
		 */
		Entity(Scene & scene, const PString & name, float posX, float posY, float angleDegrees = 0.f, bool active = true, EntityType type = EntityType::UNDEFINED, uint16_t maskBits = EntityType::UNDEFINED | EntityType::FLOOR) : 
			scene_(scene),
			name_(name),
			isActive_(active),
			startTransform_(b2Vec2(posX, posY), b2Rot(angleDegrees)),
			type_(type),
			maskBits_(maskBits),
			circlesColor_(178, 0, 255),
			edgesColor_(Color::Green),
			polygonsColor_(255, 158, 12)
		{}

		Entity(const Entity& other) = delete;
		Entity(Entity&& other) = delete;

		/**
		 * @brief Destroy the Entity object
		 * 
		 */
		~Entity()
		{
			bodies_.clear();
			joints_.clear();
			bodiesStartPositions_.clear();
		}

	public:

		/**
		 * @brief Update this object
		 * 
		 * @param deltaTime 
		 */
		void update(float deltaTime)
		{
			auxiliar_update(deltaTime);
		}

		/**
		 * @brief render the elements of this object in the received window
		 * 
		 * @param window 
		 */
		void render(RenderWindow& window);
		
	protected:

		/**
		 * @brief complementary method to add more logic to the update method inchild objects 
		 * 
		 * @param deltaTime 
		 */
		virtual void auxiliar_update(float deltaTime)
		{}

		/**
		 * @brief complementary method to render elements from child objects 
		 * 
		 * @param window 
		 */
		virtual void auxiliar_render(RenderWindow& window)
		{}

	public:

		/**
		 * @brief add a Box2D body with the definitions received
		 * 
		 * @param bodyDef 
		 * @param bodyName 
		 * @param bodyType 
		 * @return b2Body* 
		 */
		b2Body* add_body(const b2BodyDef* bodyDef, const PString& bodyName, const b2BodyType& bodyType = b2BodyType::b2_staticBody);

		/**
		 * @brief add a fixture to a body by name
		 * 
		 * @param bodyName 
		 * @param fixtureDef 
		 * @param isSensor 
		 * @return b2Fixture* 
		 */
		b2Fixture* add_fixture_to(const PString & bodyName, b2FixtureDef* fixtureDef, bool isSensor = false)
		{
			if (exists_body(bodyName))
			{
				add_fixture_to(bodies_[bodyName], fixtureDef, isSensor);
			}

			return nullptr;
		}

		/**
		 * @brief add a fixture to the input body with the definitions
		 * 
		 * @param body 
		 * @param fixtureDef 
		 * @param isSensor 
		 * @return b2Fixture* 
		 */
		b2Fixture* add_fixture_to(b2Body* body, b2FixtureDef* fixtureDef, bool isSensor = false)
		{
			if (body && fixtureDef)
			{
				fixtureDef->isSensor = isSensor;
				fixtureDef->filter.categoryBits = type_;
				fixtureDef->filter.maskBits = maskBits_;

				b2Fixture* fixture = body->CreateFixture(fixtureDef);
				fixture->SetUserData(this);

				return fixture;
			}
				
			return nullptr;
		}

		/**
		 * @brief join two bodies with the definition received
		 * 
		 * @param jointDef 
		 * @return b2Joint* 
		 */
		b2Joint* add_joint(const b2JointDef* jointDef);

	public:

		/**
		 * @brief Reset all bodies
		 * 
		 */
		void reset()
		{
			for (auto& pair : bodies_)
			{
				b2Transform& tempT = bodiesStartPositions_[pair.first];
				pair.second->SetTransform(tempT.p, tempT.q.GetAngle());
				pair.second->SetLinearVelocity(b2Vec2(0, 0));
				pair.second->SetAngularVelocity(0);
			}
		}

		/**
		 * @brief Set active this
		 * 
		 * @param state 
		 */
		void set_active(bool state = true)
		{
			isActive_ = state; 

			for (auto& pair : bodies_)
			{
				pair.second->SetActive(isActive_);
			}
		}

		/**
		 * @brief Set the type
		 * 
		 * @param type 
		 */
		void set_type(EntityType type)
		{
			type_ = type;
		}

		/**
		 * @brief Set the collision filter object
		 * 
		 * @param maskBits 
		 */
		void set_collision_filter(uint16_t maskBits)
		{
			maskBits_ = maskBits;
		}

		/**
		 * @brief Return true or false depending if exists the body by name received
		 * 
		 * @param bodyName 
		 * @return true 
		 * @return false 
		 */
		bool exists_body(const PString& bodyName)
		{
			if (bodies_.find(bodyName) != bodies_.end())
			{
				return true;
			}

			return false;
		}

		/**
		 * @brief Set the colors of this object bodies 
		 * 
		 * @param circlesColor 
		 * @param edgesColor 
		 * @param polygonsColor 
		 */
		void set_colors(const Color& circlesColor, const Color& edgesColor, const Color& polygonsColor)
		{
			set_circles_color(circlesColor);
			set_edges_color(edgesColor);
			set_polygons_color(polygonsColor);
		}

		/**
		 * @brief Set the circles color
		 * 
		 * @param circlesColor 
		 */
		void set_circles_color(const Color& circlesColor)
		{
			circlesColor_ = circlesColor;
		}

		/**
		 * @brief Set the edges color 
		 * 
		 * @param edgesColor 
		 */
		void set_edges_color(const Color& edgesColor)
		{
			edgesColor_ = edgesColor;
		}

		/**
		 * @brief Set the polygons color 
		 * 
		 * @param polygonsColor 
		 */
		void set_polygons_color(const Color& polygonsColor)
		{
			polygonsColor_ = polygonsColor;
		}

	public:

		/**
		 * @brief get the active state of this object
		 * 
		 * @return true 
		 * @return false 
		 */
		inline bool isActive() const
		{
			return isActive_;
		}

		/**
		 * @brief get the name
		 * 
		 * @return const PString& 
		 */
		inline const PString& name() const
		{
			return name_;
		}

		/**
		 * @brief get the Entity type
		 * 
		 * @return EntityType 
		 */
		inline EntityType type()
		{
			return type_;
		}

		/**
		 * @brief returns a body by name
		 * 
		 * @param name 
		 * @return b2Body* 
		 */
		inline b2Body* get_body(const PString& name)
		{
			if (exists_body(name))
			{
				return bodies_[name];
			}

			return nullptr;
		}

	protected:

		PMap< PString, b2Body* >		bodies_;
		PBuffer< b2Joint* >				joints_;
		PMap< PString, b2Transform >	bodiesStartPositions_;

	protected:

		b2Transform startTransform_;

	protected:

		Scene & scene_;
		bool isActive_;

		PString name_;
		EntityType type_;
		uint16_t maskBits_;

	protected:

		Color circlesColor_;
		Color edgesColor_;
		Color polygonsColor_;
	};
}// !namespace prz

#endif // !BOX2D_ANIMATED_SCENE_ENTITY_H_
