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

		Entity(Scene & scene, bool active = true)
			:
			scene_(scene)
		{}

		~Entity()
		{

		}

	public:

		void update(float deltaTime)
		{

		}

	public:

		
		void add_body(const b2BodyDef* bodyDefinition, const PString & name, bool isSensor = false)
		{
			bodies_[name] = scene_.create_body(bodyDefinition);

			if (isSensor)
			{
			}
		}

		void add_sensor(b2BodyDef* bodyDefinition, const PString & name)
		{
			
		}


		bool create_joint(const PString& nameBody1, const PString& nameBody2, b2JointDef* jointDefinition)
		{
			auto end = bodies_.end();
			if (bodies_.find(nameBody1) != end && bodies_.find(nameBody2) != end)
			{
				joints_.push_back(scene_.create_joint(jointDefinition));
				return true;
			}

			return false;
		}

	public:

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

		bool body_exists(const PString& name)
		{
			if (bodies_.find(name) != bodies_.end())
			{
				return true;
			}

			return false;
		}

	public:

		bool isActive()
		{
			return isActive_;
		}

		const PString& name()
		{
			return name_;
		}

		PShared_ptr<b2Body> get_body(const PString& name)
		{
			if (body_exists(name))
			{
				return PShared_ptr<b2Body>(bodies_[name]);
			}

			return PShared_ptr<b2Body>();
		}

	protected:

		PMap< PString, PShared_ptr<b2Body> >	bodies_;
		PBuffer< PShared_ptr<b2Joint> >			joints_;
		PBuffer< b2Body& >						sensors_;

	protected:

		Scene & scene_;
		EntityCategory entityCategory_;

		PString name_;
		bool isActive_;
	};
}

#endif // !BOX2D_ANIMATED_SCENE_ENTITY_H_
