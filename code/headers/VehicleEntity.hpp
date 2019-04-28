/**
 * @file VehicleEntity.hpp
 * @author Pablo Rodr�guez Zurro (przuro@gmail.com)
 * @brief Entity with capacity to rotate bodies joined by revolute joints 
 * @version 0.1
 * @date 2019-03-23
 *
 * @copyright Copyright (c) 2019
 *
 */

#ifndef BOX2D_ANIMATED_SCENE_VEHICLE_ENTITY_H_
#define BOX2D_ANIMATED_SCENE_VEHICLE_ENTITY_H_

#include "Entity.hpp"
#include "Scene.hpp"
#include "InputManager.hpp"

#include "internal/declarations/Declarations.hpp"

#include <SFML/Graphics.hpp>

namespace prz
{
	/**
	 * @brief Entity with capacity to rotate bodies joined by revolute joints 
	 * 
	 */
	class VehicleEntity : public Entity
	{
	public:

		/**
		 * @brief Construct a new Vehicle Entity object
		 * 
		 * @param leftKey 
		 * @param rightKey 
		 * @param speed 
		 * @param scene 
		 * @param name 
		 * @param posX 
		 * @param posY 
		 * @param angleDegrees 
		 * @param active 
		 */
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

		/**
		 * @brief method to add speed to the revolute joints by keyboard input
		 * 
		 * @param deltaTime 
		 */
		virtual void auxiliar_update(float deltaTime) override
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

			vehicle_auxiliar_update(deltaTime);
		}

	public:

		/**
		 * @brief special method to add more logic to the update in child implementation
		 * 
		 * @param deltaTime 
		 */
		virtual void vehicle_auxiliar_update(float deltaTime)
		{}

	public:

		/**
		 * @brief add a revolute joint with the input definition
		 * 
		 * @param wheelJointDef 
		 * @return b2RevoluteJoint* 
		 */
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