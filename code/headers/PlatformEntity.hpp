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
	public:

		PlatformEntity(b2Body* supportBody, const b2Vec2& anchorSeparation, PBuffer<b2Vec2>& polygonPoints, float upperTranslation, float motorsSpeed, Scene& scene, const PString& name, float posX, float posY, float angleDegrees = 0.f, bool active = true)
			: 
			FloorEntity(polygonPoints, scene, name, posX, posY, angleDegrees, active),
			motorsSpeed_(motorsSpeed)
		{
			type_ = EntityType::PLATFORM;

			bodies_[name_+"_polygon"]->SetType(b2_dynamicBody);

			set_collision_filter(EntityType::BALL | EntityType::VEHICLE);

			b2Body* mainBody = get_body(name_ + "_polygon");

			b2PrismaticJointDef prismaticJointDef;
			prismaticJointDef.bodyA = mainBody;
			prismaticJointDef.bodyB = supportBody;
			prismaticJointDef.collideConnected = false;
			prismaticJointDef.enableMotor = false;
			prismaticJointDef.maxMotorForce = 1000000.f;
			prismaticJointDef.motorSpeed = 200.f;
			prismaticJointDef.enableLimit = true;
			prismaticJointDef.lowerTranslation = upperTranslation;
			prismaticJointDef.upperTranslation =  0.f;
			prismaticJointDef.localAxisA = {0.f, -1.f};
			prismaticJoints_.push_back(static_cast<b2PrismaticJoint*>(add_joint(&prismaticJointDef)));
		}

	public:

		void enable_motors(bool enabled)
		{
			for (b2PrismaticJoint* prismaticJoint : prismaticJoints_)
			{
				prismaticJoint->EnableMotor(enabled);
			}
		} 

		void recieve_collision(EntityType otherType)
		{

		}



	private:

		PBuffer<b2PrismaticJoint*> prismaticJoints_;

		float motorsSpeed_;
	};
} // !namespace prz
#endif // !BOX2D_ANIMATED_SCENE_PLATFORM_ENTITY_H_
