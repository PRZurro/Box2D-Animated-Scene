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

		CarVehicleEntity(Key leftKey, Key rightKey, float wheelsSpeed, Key leftPrismaticJointKey, Key rightPrismaticJointKey, float prismaticJointsSpeed, Scene & scene, const PString & name, float posX, float posY, float angleDegrees = 0.f, bool active = true)
			:
			VehicleEntity(leftKey, rightKey, wheelsSpeed, scene, name, posX, posY, angleDegrees, active),
			leftPrismaticJointKey_(leftPrismaticJointKey),
			rightPrismaticJointKey_(rightPrismaticJointKey),
			prismaticJointsSpeed_(prismaticJointsSpeed)
		{
			///////////////////////////////////CHASIS CREATION////////////////////////////////////

			const int verticesCount = 4;

			b2Vec2 chasisLeftLimitVerts[verticesCount] =
			{
				{-25.0f, 0.0f},
				{-25.0f, 50.0f},
				{-12.0f, 50.0f},
				{-12.0f, 0.0f}
			};

			b2Vec2 chasisRightLimitVerts[verticesCount] =
			{
				{12.0f, 0.0f},
				{25.0f, 0.0f},
				{25.0f, 50.0f},
				{12.0f, 50.0f}
			};

			b2Vec2 chasisBottomLimitVerts[verticesCount] =
			{
				{-25.0f, 30.0f},
				{-25.0f, 0.0f},
				{25.0f, 0.0f},
				{25.0f, 30.0f}
			};

			// Create shapes
			b2PolygonShape chasisLeftLimitShape;
			chasisLeftLimitShape.Set(chasisLeftLimitVerts, verticesCount);

			b2PolygonShape chasisRightLimitShape;
			chasisRightLimitShape.Set(chasisRightLimitVerts, verticesCount);

			b2PolygonShape chasisBottomLimitShape;
			chasisBottomLimitShape.Set(chasisBottomLimitVerts, verticesCount);
			
			// Create chasis fixture definitions

			b2FixtureDef chasisLeftFixtureDef;
			chasisLeftFixtureDef.shape = &chasisLeftLimitShape;
			chasisLeftFixtureDef.density = 1.0f;
			chasisLeftFixtureDef.restitution = 0.2f;
			chasisLeftFixtureDef.friction = 0.50f;

			b2FixtureDef chasisRightFixtureDef;
			chasisRightFixtureDef.shape = &chasisRightLimitShape;
			chasisRightFixtureDef.density = 1.0f;
			chasisRightFixtureDef.restitution = 0.2f;
			chasisRightFixtureDef.friction = 0.50f;

			b2FixtureDef chasisBottomFixtureDef;
			chasisBottomFixtureDef.shape = &chasisBottomLimitShape;
			chasisBottomFixtureDef.density = 1.0f;
			chasisBottomFixtureDef.restitution = 0.75f;
			chasisBottomFixtureDef.friction = 0.50f;

			//Create chasis body and it's fixtures 
			b2BodyDef chasisBodyDef;
			b2Body * chasisBody = add_body(&chasisBodyDef, "chasis", b2_dynamicBody);

			add_fixture_to("chasis", &chasisLeftFixtureDef);
			add_fixture_to("chasis", &chasisRightFixtureDef);
			add_fixture_to("chasis", &chasisBottomFixtureDef);

			///////////////////////////////////WHEELS CREATION////////////////////////////////////
			// Wheel positions
			b2Vec2 leftWheelPositionOffset(-30.5f, -0.5f);
			b2Vec2 rightWheelPositionOffset(30.5f, -0.5f);
			
			// Creating both wheels fixtures and bodies
			b2BodyDef leftWheelBodyDef;

			b2CircleShape leftWheelBodyShape;
			leftWheelBodyShape.m_radius = 10.f;

			b2FixtureDef leftWheelBodyFixture;
			leftWheelBodyFixture.shape = &leftWheelBodyShape;
			leftWheelBodyFixture.density = 1.0f;
			leftWheelBodyFixture.restitution = 0.75f;
			leftWheelBodyFixture.friction = 0.50f;

			b2Body* leftWheelBody = add_body(&leftWheelBodyDef, name_, b2_dynamicBody);
			leftWheelBody->CreateFixture(&leftWheelBodyFixture);
			leftWheelBody->SetTransform(leftWheelBody->GetPosition() + leftWheelPositionOffset, leftWheelBody->GetAngle());

			b2BodyDef leftWheelAxleBodyDef;

			b2CircleShape leftWheelAxleBodyShape;
			leftWheelAxleBodyShape.m_radius = 3.f;

			b2FixtureDef leftWheelAxleBodyFixture;
			leftWheelAxleBodyFixture.shape = &leftWheelAxleBodyShape;
			leftWheelAxleBodyFixture.density = 1.0f;
			leftWheelAxleBodyFixture.restitution = 0.75f;
			leftWheelAxleBodyFixture.friction = 0.30f;

			b2Body* leftWheelAxleBody = add_body(&leftWheelAxleBodyDef, name_, b2_dynamicBody);
			leftWheelAxleBody->CreateFixture(&leftWheelAxleBodyFixture);
			leftWheelAxleBody->SetTransform(leftWheelAxleBody->GetPosition() + leftWheelPositionOffset, leftWheelAxleBody->GetAngle());

			b2BodyDef rightWheelBodyDef;

			b2CircleShape rightWheelBodyShape;
			rightWheelBodyShape.m_radius = 10.f;

			b2FixtureDef rightWheelBodyFixture;
			rightWheelBodyFixture.shape = &rightWheelBodyShape;
			rightWheelBodyFixture.density = 1.0f;
			rightWheelBodyFixture.restitution = 0.75f;
			rightWheelBodyFixture.friction = 0.3f;

			b2Body* rightWheelBody = add_body(&rightWheelBodyDef, name_, b2_dynamicBody);
			rightWheelBody->CreateFixture(&rightWheelBodyFixture);
			rightWheelBody->SetTransform(rightWheelBody->GetPosition() + rightWheelPositionOffset, rightWheelBody->GetAngle());

			b2BodyDef rightWheelAxleBodyDef;

			b2CircleShape rightWheelAxleBodyShape;
			rightWheelAxleBodyShape.m_radius = 3.f;

			b2FixtureDef rightWheelAxleBodyFixture;
			rightWheelAxleBodyFixture.shape = &rightWheelAxleBodyShape;
			rightWheelAxleBodyFixture.density = 1.0f;
			rightWheelAxleBodyFixture.restitution = 0.75f;
			rightWheelAxleBodyFixture.friction = 0.50f;

			b2Body* rightWheelAxleBody = add_body(&rightWheelAxleBodyDef, name_, b2_dynamicBody);
			rightWheelAxleBody->CreateFixture(&rightWheelAxleBodyFixture);
			rightWheelAxleBody->SetTransform(rightWheelAxleBody->GetPosition() + rightWheelPositionOffset, rightWheelAxleBody->GetAngle());

			// Create the joints attached to the pieces
			b2RevoluteJointDef leftWheelRevoluteJointDef;
			leftWheelRevoluteJointDef.bodyA = leftWheelAxleBody;
			leftWheelRevoluteJointDef.bodyB = leftWheelBody;
			leftWheelRevoluteJointDef.enableMotor = true;
			leftWheelRevoluteJointDef.motorSpeed = 0.f;
			leftWheelRevoluteJointDef.maxMotorTorque = 100000.f;
			b2RevoluteJoint* leftRevoluteWheelJoint = add_revolute_joint(leftWheelRevoluteJointDef);

			b2PrismaticJointDef leftWheelPrismaticJointDef;
			leftWheelPrismaticJointDef.bodyA = leftWheelAxleBody;
			leftWheelPrismaticJointDef.bodyB = chasisBody;
			leftWheelPrismaticJointDef.localAnchorB = leftWheelPositionOffset;
			leftWheelPrismaticJointDef.enableMotor = true;
			leftWheelPrismaticJointDef.maxMotorForce = 1000000.f;
			leftWheelPrismaticJointDef.enableLimit = true;
			leftWheelPrismaticJointDef.lowerTranslation = 20.f;
			leftWheelPrismaticJointDef.upperTranslation = 70.f;
			leftWheelPrismaticJointDef.referenceAngle = -to_radians(90.f);
			b2PrismaticJoint* leftWheelPrismaticJoint = add_prismatic_joint(leftWheelPrismaticJointDef);
			
			b2RevoluteJointDef rightWheelRevoluteJointDef;
			rightWheelRevoluteJointDef.bodyA = rightWheelAxleBody;
			rightWheelRevoluteJointDef.bodyB = rightWheelBody;
			rightWheelRevoluteJointDef.enableMotor = true;
			rightWheelRevoluteJointDef.maxMotorTorque = 100000.f;
			b2RevoluteJoint* rightRevoluteWheelJoint = add_revolute_joint(rightWheelRevoluteJointDef);

			b2PrismaticJointDef rightWheelPrismaticJointDef;
			rightWheelPrismaticJointDef.bodyA = rightWheelAxleBody;
			rightWheelPrismaticJointDef.bodyB = chasisBody;
			rightWheelPrismaticJointDef.localAnchorB = rightWheelPositionOffset;
			rightWheelPrismaticJointDef.enableMotor = true;
			rightWheelPrismaticJointDef.maxMotorForce = 1000000.f;
			rightWheelPrismaticJointDef.enableLimit = true;
			rightWheelPrismaticJointDef.lowerTranslation = 20.f;
			rightWheelPrismaticJointDef.upperTranslation = 70.f;
			rightWheelPrismaticJointDef.referenceAngle = -to_radians(90.f);
			b2PrismaticJoint* rightWheelPrismaticJoint = add_prismatic_joint(rightWheelPrismaticJointDef);
		}

	public:

		b2PrismaticJoint* add_prismatic_joint(const b2PrismaticJointDef& prismaticJointDef)
		{
			b2PrismaticJoint* prismaticJoint = static_cast<b2PrismaticJoint*>(add_joint(&prismaticJointDef));
			prismaticJoints_.push_back(prismaticJoint);

			return prismaticJoint;
		}

	private:

		virtual void auxiliar_update() override
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

			prismaticJoints_[0]->SetMotorSpeed(speedLeftWheelPrismaticJoint); 
			prismaticJoints_[1]->SetMotorSpeed(speedRightWheelPrismaticJoint);
		}

	private:

		PBuffer< b2PrismaticJoint* > prismaticJoints_;

		Key leftPrismaticJointKey_;
		Key rightPrismaticJointKey_;

		float prismaticJointsSpeed_;
	};

} // !namespace prz
#endif // !BOX2D_ANIMATED_SCENE_CAR_VEHICLE_ENTITY_H_
