#include "PlatformEntity.hpp"

namespace prz
{
	PlatformEntity::PlatformEntity(b2Body* supportBody, PBuffer<b2Vec2>& polygonPoints, float lowerTranslation, float upperTranslation, float timerTime, float motorSpeed, Scene& scene, const PString& name, float posX, float posY, float angleDegrees, bool active) :
		FloorEntity(polygonPoints, scene, name, posX, posY, angleDegrees, active),
		motorSpeed_(motorSpeed),
		addStartContactTime_(false),
		addEndContactTime_(false),
		timeSinceStartContact_(0.f),
		timeSinceEndContact_(0.f),
		timerTime_(timerTime)
	{
		type_ = EntityType::PLATFORM;

		bodies_[name_ + "_polygon"]->SetType(b2_dynamicBody);

		set_collision_filter(EntityType::BALL | EntityType::VEHICLE);
		set_polygons_color(Color::Yellow);

		b2Filter filter;
		filter.categoryBits = type_;
		filter.maskBits = maskBits_;

		bodies_[name_ + "_polygon"]->GetFixtureList()->SetFilterData(filter);
		bodies_[name_ + "_polygon"]->GetFixtureList()->SetUserData(this);

		b2Body * mainBody = get_body(name_ + "_polygon");

		b2PrismaticJointDef prismaticJointDef;
		prismaticJointDef.bodyA = mainBody;
		prismaticJointDef.bodyB = supportBody;
		prismaticJointDef.enableMotor = true;
		prismaticJointDef.maxMotorForce = 10000000000.f;
		prismaticJointDef.motorSpeed = 0.f;
		prismaticJointDef.enableLimit = true;
		prismaticJointDef.lowerTranslation = lowerTranslation;
		prismaticJointDef.upperTranslation = upperTranslation;
		prismaticJointDef.localAxisA = { 0.f, -1.f };
		prismaticJoint_ = static_cast<b2PrismaticJoint*>(add_joint(&prismaticJointDef));
	}
	void PlatformEntity::auxiliar_update(float deltaTime)
	{
		float curSpeed = -150.f;

		if (addEndContactTime_)
		{
			timeSinceEndContact_ += deltaTime;
		}
		else if (addStartContactTime_)
		{
			timeSinceStartContact_ += deltaTime;
		}

		if (timeSinceEndContact_ >= timerTime_)
		{
			timeSinceStartContact_ = 0.f;
		}

		if (timeSinceStartContact_ >= timerTime_)
		{
			curSpeed = motorSpeed_;
		}

		prismaticJoint_->SetMotorSpeed(curSpeed);
	}
}
