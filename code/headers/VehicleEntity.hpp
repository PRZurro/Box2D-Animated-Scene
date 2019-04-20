#pragma once
/**
 * @file VehicleEntity.hpp
 * @author Pablo Rodríguez Zurro (przuro@gmail.com)
 * @brief
 * @version 0.1
 * @date 2019-03-23
 *
 * @copyright Copyright (c) 2019
 *
 */

#ifndef BOX2D_ANIMATED_SCENE_VEHICLE_ENTITY_H_
#define BOX2D_ANIMATED_SCENE_VEHICLE_ENTITY_H_

#include "internal/declarations/Declarations.hpp"

#include "Entity.hpp"
#include "Scene.hpp"
#include "InputManager.hpp"

#include <SFML/Graphics.hpp>

namespace prz
{
	class VehicleEntity : public Entity
	{
	public:

		VehicleEntity(Key& leftKey, Key& rightKey, float speed, Scene & scene, const PString & name, float posX, float posY, float angleDegrees = 0.f, bool active = true)
			:
			Entity(scene, name, posX, posY, angleDegrees, active, EntityType::VEHICLE),
			leftKey_(leftKey),
			rightKey_(rightKey),
			wheelsSpeed_(speed)
		{
			set_collision_filter(EntityType::BALL | EntityType::FINISH | EntityType::PARTICLE_EMITTER | EntityType::PLATFORM | EntityType::FLOOR);

			set_colors(Color(38, 255, 0), Color::Magenta, Color(255, 102, 0));
		}

	public:

		virtual void update(float deltaTime) override
		{
			InputManager & inputManager = InputManager::instance();

			float speed = 0.f;

			if (inputManager.is_key_pressed(leftKey_))
			{
				speed = wheelsSpeed_;
			}
			else if (inputManager.is_key_pressed(rightKey_))
			{
				speed = -wheelsSpeed_;
			}

			for (b2RevoluteJoint* revoluteJoint : revoluteJoints_)
			{
				revoluteJoint->SetMotorSpeed(speed);
			}

			auxiliar_update(deltaTime);
		}

	public:

		virtual void auxiliar_update(float deltaTime)
		{}

	public:

		b2RevoluteJoint * add_revolute_joint(const b2RevoluteJointDef & wheelJointDef)
		{
			b2RevoluteJoint* revoluteJoint = static_cast<b2RevoluteJoint*>(add_joint(&wheelJointDef));
			revoluteJoints_.push_back(revoluteJoint);

			return revoluteJoint;
		}

	protected:

		PBuffer< b2RevoluteJoint* > revoluteJoints_;
		
		Key leftKey_;
		Key rightKey_;

		float wheelsSpeed_;
	};
}

#endif // !BOX2D_ANIMATED_SCENE_VEHICLE_ENTITY_H_