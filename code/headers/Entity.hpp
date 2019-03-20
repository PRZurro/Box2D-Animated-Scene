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
#include "Box2D/Box2D.h"

namespace prz
{
	class Scene;

	class Entity
	{
	public:

		Entity(Scene & scene, const PString & name, float posX, float posY, float angleDegrees, bool active = true)
			:
			scene_(scene),
			name_(name),
			isActive_(active)
		{}

		~Entity()
		{
		}

	public:

		b2Body* add_body(const b2BodyDef* bodyDef, const PString& bodyName, const b2BodyType& bodyType = b2BodyType::b2_staticBody);

		void add_fixture_to(const PString & bodyName, b2FixtureDef* fixtureDef, bool isSensor = false)
		{
			if (exists_body(bodyName))
			{
				fixtureDef->isSensor = isSensor;
				bodies_[bodyName]->CreateFixture(fixtureDef);
			}
		}

		b2Joint* join(const PString& bodyNameA, const PString& bodyNameB, bool collide = false, bool revolute = false);

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

		bool exists_body(const PString& bodyName)
		{
			if (bodies_.find(bodyName) != bodies_.end())
			{
				return true;
			}

			return false;
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
		EntityCategory entityCategory_;
	};
}

#endif // !BOX2D_ANIMATED_SCENE_ENTITY_H_