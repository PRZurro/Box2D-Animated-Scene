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

		PlatformEntity(b2Body* supportBody, PBuffer<b2Vec2>& polygonPoints, float lowerTranslation, float upperTranslation, float timerTime, float motorSpeed, Scene& scene, const PString& name, float posX, float posY, float angleDegrees = 0.f, bool active = true)
			: 
			FloorEntity(polygonPoints, scene, name, posX, posY, angleDegrees, active),
			motorSpeed_(motorSpeed),
			addTime_(false),
			curTimerTime_(0.f),
			timerTime_(timerTime)
		{
			type_ = EntityType::PLATFORM;

			bodies_[name_+"_polygon"]->SetType(b2_dynamicBody);

			set_collision_filter(EntityType::BALL | EntityType::VEHICLE);

			b2Body* mainBody = get_body(name_ + "_polygon");

			b2PrismaticJointDef prismaticJointDef;
			prismaticJointDef.bodyA = mainBody;
			prismaticJointDef.bodyB = supportBody;
			prismaticJointDef.collideConnected = false;
			prismaticJointDef.enableMotor = true;
			prismaticJointDef.maxMotorForce = 10000000000.f;
			prismaticJointDef.motorSpeed = 0.f;
			prismaticJointDef.enableLimit = true;
			prismaticJointDef.lowerTranslation = lowerTranslation;
			prismaticJointDef.upperTranslation = upperTranslation;
			prismaticJointDef.localAxisA = {0.f, -1.f};
			prismaticJoint_ = static_cast<b2PrismaticJoint*>(add_joint(&prismaticJointDef));
		}
	
	public:

		virtual void update(float deltaTime) override
		{
			float curSpeed = 0.f;

			if (addTime_)
			{
				curTimerTime_ += deltaTime;
			}
			else
			{
				curTimerTime_ = 0.f;
			}

			if (curTimerTime_ >= timerTime_)
			{
				curSpeed = motorSpeed_;
			}

			prismaticJoint_->SetMotorSpeed(curSpeed);
		}

	public:

		void increase_timer()
		{
			bool addTime_ = true;
		}

		

	private:

		b2PrismaticJoint* prismaticJoint_;

		float motorSpeed_;

		bool addTime_;

		float curTimerTime_;
		float timerTime_;
	};
} // !namespace prz
#endif // !BOX2D_ANIMATED_SCENE_PLATFORM_ENTITY_H_
