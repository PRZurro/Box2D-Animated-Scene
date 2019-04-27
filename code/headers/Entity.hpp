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

		~Entity()
		{
			bodies_.clear();
			joints_.clear();
			bodiesStartPositions_.clear();
		}

	public:

		void update(float deltaTime)
		{
			auxiliar_update(deltaTime);
		}

		void render(RenderWindow& window);
		
	protected:

		virtual void auxiliar_update(float deltaTime)
		{}

		virtual void auxiliar_render(RenderWindow& window)
		{}

	public:

		b2Body* add_body(const b2BodyDef* bodyDef, const PString& bodyName, const b2BodyType& bodyType = b2BodyType::b2_staticBody);

		b2Joint* add_joint(const b2JointDef* jointDef);

		b2Fixture* add_fixture_to(const PString & bodyName, b2FixtureDef* fixtureDef, bool isSensor = false)
		{
			if (exists_body(bodyName))
			{
				add_fixture_to(bodies_[bodyName], fixtureDef, isSensor);
			}

			return nullptr;
		}

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

	public:

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

		void set_active(bool state = true)
		{
			isActive_ = state; 

			for (auto& pair : bodies_)
			{
				pair.second->SetActive(isActive_);
			}
		}

		void set_type(EntityType type)
		{
			type_ = type;
		}

		void set_collision_filter(uint16_t maskBits)
		{
			maskBits_ = maskBits;
		}

		bool exists_body(const PString& bodyName)
		{
			if (bodies_.find(bodyName) != bodies_.end())
			{
				return true;
			}

			return false;
		}

		void set_colors(const Color& circlesColor, const Color& edgesColor, const Color& polygonsColor)
		{
			set_circles_color(circlesColor);
			set_edges_color(edgesColor);
			set_polygons_color(polygonsColor);
		}

		void set_circles_color(const Color& circlesColor)
		{
			circlesColor_ = circlesColor;
		}

		void set_edges_color(const Color& edgesColor)
		{
			edgesColor_ = edgesColor;
		}

		void set_polygons_color(const Color& polygonsColor)
		{
			polygonsColor_ = polygonsColor;
		}

	public:

		inline bool isActive() const
		{
			return isActive_;
		}

		inline const PString& name() const
		{
			return name_;
		}

		inline EntityType type()
		{
			return type_;
		}

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
}
#endif // !BOX2D_ANIMATED_SCENE_ENTITY_H_
