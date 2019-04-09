/**
 * @file PlatformEntity.hpp
 * @author Pablo Rodríguez Zurro (przuro@gmail.com)
 * @brief
 * @version 0.1
 * @date 2019-04-09
 *
 * @copyright Copyright (c) 2019
 *
 */

#ifndef BOX2D_ANIMATED_SCENE_PLATFORM_ENTITY_H_
#define BOX2D_ANIMATED_SCENE_PLATFORM_ENTITY_H_

#include "internal/declarations/Declarations.hpp"
#include "internal/Utilities.hpp"

#include "FloorEntity.hpp"

namespace prz
{
	class PlatformEntity : public FloorEntity
	{
		PlatformEntity(b2Body* supportBody, const b2Vec2& anchorSeparation, PBuffer<b2Vec2>& polygonPoints, float upperTranslation, float motorsSpeed, Scene& scene, const PString& name, float posX, float posY, float angleDegrees = 0.f, bool active = true)
			: 
			FloorEntity(polygonPoints, scene, name, posX, posY, angleDegrees, active, EntityType::PLATFORM),
			motorsSpeed_(motorsSpeed)
		{
			b2Body* mainBody = get_body(name_ + "_polygon");

			b2PrismaticJointDef leftPrismaticJointDef;
			leftPrismaticJointDef.bodyA = mainBody;
			leftPrismaticJointDef.bodyB = supportBody;
			leftPrismaticJointDef.collideConnected = false;
			leftPrismaticJointDef.localAnchorB = b2Vec2(-anchorSeparation.x, anchorSeparation.y);
			leftPrismaticJointDef.enableMotor = false;
			leftPrismaticJointDef.maxMotorForce = 1000000.f;
			leftPrismaticJointDef.motorSpeed = motorsSpeed_;
			leftPrismaticJointDef.enableLimit = true;
			leftPrismaticJointDef.lowerTranslation = 0.f;
			leftPrismaticJointDef.upperTranslation = upperTranslation;
			leftPrismaticJointDef.referenceAngle = -to_radians(90.f);
			prismaticJoints_.push_back(static_cast<b2PrismaticJoint*>(add_joint(&leftPrismaticJointDef)));

			b2PrismaticJointDef rightPrismaticJointDef;
			rightPrismaticJointDef.bodyA = mainBody;
			rightPrismaticJointDef.bodyB = supportBody;
			rightPrismaticJointDef.collideConnected = false;
			rightPrismaticJointDef.localAnchorB = b2Vec2(anchorSeparation.x, anchorSeparation.y);
			rightPrismaticJointDef.enableMotor = false;
			rightPrismaticJointDef.maxMotorForce = 1000000.f;
			rightPrismaticJointDef.motorSpeed = motorsSpeed_;
			rightPrismaticJointDef.enableLimit = true;
			rightPrismaticJointDef.lowerTranslation = 0.f;
			rightPrismaticJointDef.upperTranslation = upperTranslation;
			rightPrismaticJointDef.referenceAngle = -to_radians(90.f);
			prismaticJoints_.push_back(static_cast<b2PrismaticJoint*>(add_joint(&rightPrismaticJointDef)));
		}

	public:

		void enable_motors(bool enabled)
		{
			for (b2PrismaticJoint* prismaticJoint : prismaticJoints_)
			{
				prismaticJoint->EnableMotor(enabled);
			}
		}

	private:

		PBuffer<b2PrismaticJoint*> prismaticJoints_;

		float motorsSpeed_;
	};
} // !namespace prz
#endif // !BOX2D_ANIMATED_SCENE_PLATFORM_ENTITY_H_
