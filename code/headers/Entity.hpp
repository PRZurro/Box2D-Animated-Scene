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

		Entity(Scene & scene, const PString & name, b2Transform & transform, bool active = true)
			:
			scene_(scene),
			name_(name),
			isActive_(active),
			startTransform_(transform)
		{}

		~Entity()
		{}

	public:

		void render(float deltaTime)
		{
			for (auto& pair : bodies_)
			{
			}
		}

	public:

		b2Body* add_body(const b2BodyDef* bodyDef, const PString& bodyName, const PBodyType& bodyType = b2BodyType::b2_staticBody);

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

		void handle_contact(const Entity & other)
		{
			if (isActive_)
			{
				//handle contact
			}
		}

	public:

		void reset()
		{
			for (auto& pair : bodies_)
			{
				PTransform* tempT = bodiesStartPositions_[pair.first].get();
				pair.second->SetTransform(tempT->p, tempT->q.GetAngle());
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

		bool isActive() const
		{
			return isActive_;
		}

		const PString& name() const
		{
			return name_;
		}

		const PMap< PString, PShared_ptr<b2Body> >& bodies() const
		{
			return bodies_;
		}

		PShared_ptr<b2Body> get_body(const PString& name)
		{
			if (exists_body(name))
			{
				return PShared_ptr<b2Body>(bodies_[name]);
			}

			return PShared_ptr<b2Body>();
		}

	protected:

		PMap< PString, PShared_ptr<b2Body> >		bodies_;
		PBuffer< PShared_ptr<b2Joint> >				joints_;
		PMap< PString, PShared_ptr<PTransform> >	bodiesStartPositions_;

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