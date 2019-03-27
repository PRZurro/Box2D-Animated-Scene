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

		VehicleEntity(Key& leftKey, Key& rightKey, float speed, Scene & scene, const PString & name, float posX, float posY, float angleDegrees, bool active = true)
			:
			Entity(scene, name, posX, posY, angleDegrees, active),
			leftKey_(leftKey),
			rightKey_(rightKey),
			speed_(speed)
		{}

		VehicleEntity(const VehicleEntity& other)
			:
			Entity(other),
			leftKey_(other.leftKey_),
			rightKey_(other.rightKey_),
			speed_(other.speed_)
		{}

	public:
/*
		void update(const InputListener& inputListener)
		{
			float speed = 0.f;

			if (inputListener.is_key_pressed(leftKey_))
			{
				speed = -speed_;
			}
			else if (inputListener.is_key_pressed(rightKey_))
			{
				speed = speed_;
			}

			for (b2RevoluteJoint* revoluteJoint : revoluteJoints_)
			{
				revoluteJoint->SetMotorSpeed(speed_);
			}
		}
*/
	private:
		
		Key leftKey_;
		Key rightKey_;

		float speed_;
	};
}

#endif // !BOX2D_ANIMATED_SCENE_VEHICLE_ENTITY_H_