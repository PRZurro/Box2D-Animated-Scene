/**
 * @file CarVehicleEntity.hpp
 * @author Pablo Rodríguez Zurro (przuro@gmail.com)
 * @brief
 * @version 0.1
 * @date 2019-03-23
 *
 * @copyright Copyright (c) 2019
 *
 */

#ifndef BOX2D_ANIMATED_SCENE_CAR_VEHICLE_ENTITY_H_
#define BOX2D_ANIMATED_SCENE_CAR_VEHICLE_ENTITY_H_

#include "internal/declarations/Declarations.hpp"
#include "Internal/Utilities.hpp"

#include "VehicleEntity.hpp"

namespace prz
{
	class CarVehicleEntity : public VehicleEntity
	{
	public:

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

		b2PrismaticJoint* add_prismatic_joint(const b2PrismaticJointDef& prismaticJointDef)
		{
			b2PrismaticJoint* prismaticJoint = static_cast<b2PrismaticJoint*>(add_joint(&prismaticJointDef));
			prismaticJoints_.push_back(prismaticJoint);

			return prismaticJoint;
		}

	private:

		virtual void auxiliar_update(float deltaTime) override
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
