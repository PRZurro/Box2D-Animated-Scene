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

#include "Internal/Declarations/Declarations.hpp"
#include "Box2D/Box2D.h"

namespace prz
{
	class Entity
	{
	public:

		Entity(Scene & scene, b2BodyDef* fBodyDef, b2BodyDef* lBodyDef, bool active = true)
			:
			scene_(scene)
		{
			for (b2BodyDef* bodyDef = fBodyDef; bodyDef <= fBodyDef; ++bodyDef)
			{
				bodies_.push_back(scene_.create_body(bodyDef));
			}
		}

		~Entity()
		{

		}

	public:

		void update(float deltaTime)
		{

		}

	public:

		bool joint(const PString & nameBody1, const PString & nameBody2)
		{
			auto end = bodies_.end();
			if (bodies_.find(nameBody1) != end && bodies_.find(nameBody2) != end)
			{
				b2JointDef jointDef;
				joints_.push_back(PShared_ptr<b2Joint>(new b2Joint(jointDef))
			}

			return false;
		}

		void handle_contact(const Entity & other)
		{
			if (isActive_)
			{
				//handle contact
			}
		}

	public:

		void set_active(bool state = true)
		{
			isActive_ = state; 
		}

	public:

		bool isActive()
		{
			return isActive_;
		}

		const PString & name()
		{
			return name_;
		}

	protected:

		PMap< PString, PShared_ptr<b2Body> >	bodies_;
		PBuffer< PShared_ptr<b2Joint> >	joints_;
		PBuffer< b2Body&>				sensors_;

	protected:

		Scene & scene_;
		EntityCategory entityCategory_;

		PString name_;

		bool isActive_;
	};
}

#endif // !BOX2D_ANIMATED_SCENE_ENTITY_H_
