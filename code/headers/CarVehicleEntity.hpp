/**
 * @file CarVehicleEntity.hpp
 * @author Pablo Rodr�guez Zurro (przuro@gmail.com)
 * @brief Entity composed by prismatic and revolute joints that can be handled by input
 * @version 0.1
 * @date 2019-03-23
 *
 * @copyright Copyright (c) 2019
 *
 */

#ifndef BOX2D_ANIMATED_SCENE_CAR_VEHICLE_ENTITY_H_
#define BOX2D_ANIMATED_SCENE_CAR_VEHICLE_ENTITY_H_

#include "internal/declarations/Declarations.hpp"
#include "internal/Utilities.hpp"

#include "VehicleEntity.hpp"

namespace prz
{
	class CarVehicleEntity : public VehicleEntity
	{
	public:

		/**
		 * @brief Construct a new car
		 * 
		 * @param leftKey 
		 * @param rightKey 
		 * @param wheelsSpeed 
		 * @param leftPrismaticJointKey 
		 * @param rightPrismaticJointKey 
		 * @param prismaticJointsSpeed 
		 * @param scene 
		 * @param name 
		 * @param posX 
		 * @param posY 
		 * @param angleDegrees 
		 * @param active 
		 */
		CarVehicleEntity
		(
			Key leftKey,
			Key rightKey, 
			float wheelsSpeed, 
			Key leftPrismaticJointKey, 
			Key rightPrismaticJointKey, 
			float prismaticJointsSpeed, 
			Scene& scene, 
			const PString& name,
			float posX, float posY, 
			float angleDegrees = 0.f, 
			bool active = true
		);

	public:

		/**
		 * @brief Create a prismatic joint by the input definition
		 * 
		 * @param prismaticJointDef 
		 * @return b2PrismaticJoint* 
		 */
		b2PrismaticJoint* add_prismatic_joint(const b2PrismaticJointDef& prismaticJointDef)
		{
			b2PrismaticJoint* prismaticJoint = static_cast<b2PrismaticJoint*>(add_joint(&prismaticJointDef));
			prismaticJoints_.push_back(prismaticJoint);

			return prismaticJoint;
		}

	private:

		/**
		 * @brief Add the movement of the car to the parent's update method member by checking the keyboard input 
		 * 
		 * @param deltaTime 
		 */
		virtual void vehicle_auxiliar_update(float deltaTime) override
		{
			InputManager& inputManager = InputManager::instance();

			float speedLeftWheelPrismaticJoint = -10.f , speedRightWheelPrismaticJoint = speedLeftWheelPrismaticJoint;

			if (inputManager.is_key_pressed(leftPrismaticJointKey_))
			{
				speedLeftWheelPrismaticJoint = prismaticJointsSpeed_;
			}
			else if (inputManager.is_key_pressed(rightPrismaticJointKey_))
			{
				speedRightWheelPrismaticJoint = prismaticJointsSpeed_;
			}
			else if (inputManager.is_key_pressed(Key::Space))
			{
				speedLeftWheelPrismaticJoint = speedRightWheelPrismaticJoint = prismaticJointsSpeed_;
			}
			else if (inputManager.is_key_pressed(Key::E))
			{
				std::cout << "E" << std::endl;
				coverJoint_->SetMotorSpeed(-coverJoint_->GetMotorSpeed());
			}

			prismaticJoints_[0]->SetMotorSpeed(speedLeftWheelPrismaticJoint); 
			prismaticJoints_[1]->SetMotorSpeed(speedRightWheelPrismaticJoint);
		}

	private:

		PBuffer< b2PrismaticJoint* > prismaticJoints_;
		b2RevoluteJoint* coverJoint_;

		Key leftPrismaticJointKey_;
		Key rightPrismaticJointKey_;

		float prismaticJointsSpeed_;
	};

} // !namespace prz

#endif // !BOX2D_ANIMATED_SCENE_CAR_VEHICLE_ENTITY_H_
