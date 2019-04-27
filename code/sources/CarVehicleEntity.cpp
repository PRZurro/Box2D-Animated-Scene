#include "CarVehicleEntity.hpp"

namespace prz
{
	CarVehicleEntity::CarVehicleEntity
	(
		Key leftKey, 
		Key rightKey, 
		float wheelsSpeed, 
		Key leftPrismaticJointKey, 
		Key rightPrismaticJointKey, 
		float prismaticJointsSpeed, 
		Scene& scene, 
		const PString& name, 
		float posX, 
		float posY, 
		float angleDegrees, 
		bool active
	):
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
		b2Body* chasisBody = add_body(&chasisBodyDef, "chasis", b2_dynamicBody);

		add_fixture_to(chasisBody, &chasisLeftFixtureDef);
		add_fixture_to(chasisBody, &chasisRightFixtureDef);
		add_fixture_to(chasisBody, &chasisBottomFixtureDef);

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

		b2Body * leftWheelBody = add_body(&leftWheelBodyDef, "Left_Wheel", b2_dynamicBody);
		add_fixture_to(leftWheelBody, &leftWheelBodyFixture);
		leftWheelBody->SetTransform(leftWheelBody->GetPosition() + leftWheelPositionOffset, leftWheelBody->GetAngle());

		b2BodyDef leftWheelAxleBodyDef;

		b2CircleShape leftWheelAxleBodyShape;
		leftWheelAxleBodyShape.m_radius = 3.f;

		b2FixtureDef leftWheelAxleBodyFixture;
		leftWheelAxleBodyFixture.shape = &leftWheelAxleBodyShape;
		leftWheelAxleBodyFixture.density = 1.0f;
		leftWheelAxleBodyFixture.restitution = 0.75f;
		leftWheelAxleBodyFixture.friction = 0.30f;

		b2Body * leftWheelAxleBody = add_body(&leftWheelAxleBodyDef, "Left_Wheel_Axle", b2_dynamicBody);
		add_fixture_to(leftWheelAxleBody, &leftWheelAxleBodyFixture);
		leftWheelAxleBody->SetTransform(leftWheelAxleBody->GetPosition() + leftWheelPositionOffset, leftWheelAxleBody->GetAngle());

		b2BodyDef rightWheelBodyDef;

		b2CircleShape rightWheelBodyShape;
		rightWheelBodyShape.m_radius = 10.f;

		b2FixtureDef rightWheelBodyFixture;
		rightWheelBodyFixture.shape = &rightWheelBodyShape;
		rightWheelBodyFixture.density = 1.0f;
		rightWheelBodyFixture.restitution = 0.75f;
		rightWheelBodyFixture.friction = 0.3f;

		b2Body * rightWheelBody = add_body(&rightWheelBodyDef, "Right_Wheel", b2_dynamicBody);
		add_fixture_to(rightWheelBody, &rightWheelBodyFixture);
		rightWheelBody->SetTransform(rightWheelBody->GetPosition() + rightWheelPositionOffset, rightWheelBody->GetAngle());

		b2BodyDef rightWheelAxleBodyDef;

		b2CircleShape rightWheelAxleBodyShape;
		rightWheelAxleBodyShape.m_radius = 3.f;

		b2FixtureDef rightWheelAxleBodyFixture;
		rightWheelAxleBodyFixture.shape = &rightWheelAxleBodyShape;
		rightWheelAxleBodyFixture.density = 1.0f;
		rightWheelAxleBodyFixture.restitution = 0.75f;
		rightWheelAxleBodyFixture.friction = 0.50f;

		b2Body * rightWheelAxleBody = add_body(&rightWheelAxleBodyDef, "Right_Wheel_Axle", b2_dynamicBody);
		add_fixture_to(rightWheelAxleBody, &rightWheelAxleBodyFixture);
		rightWheelAxleBody->SetTransform(rightWheelAxleBody->GetPosition() + rightWheelPositionOffset, rightWheelAxleBody->GetAngle());

		// Create the joints attached to the pieces
		b2RevoluteJointDef leftWheelRevoluteJointDef;
		leftWheelRevoluteJointDef.bodyA = leftWheelAxleBody;
		leftWheelRevoluteJointDef.bodyB = leftWheelBody;
		leftWheelRevoluteJointDef.enableMotor = true;
		leftWheelRevoluteJointDef.motorSpeed = 0.f;
		leftWheelRevoluteJointDef.maxMotorTorque = 1000000.f;
		b2RevoluteJoint * leftRevoluteWheelJoint = add_revolute_joint(leftWheelRevoluteJointDef);

		b2PrismaticJointDef leftWheelPrismaticJointDef;
		leftWheelPrismaticJointDef.bodyA = leftWheelAxleBody;
		leftWheelPrismaticJointDef.bodyB = chasisBody;
		leftWheelPrismaticJointDef.localAnchorB = leftWheelPositionOffset;
		leftWheelPrismaticJointDef.enableMotor = true;
		leftWheelPrismaticJointDef.maxMotorForce = 1000000.f;
		leftWheelPrismaticJointDef.enableLimit = true;
		leftWheelPrismaticJointDef.lowerTranslation = 0.f;
		leftWheelPrismaticJointDef.upperTranslation = 300.f;
		leftWheelPrismaticJointDef.localAxisA = { 0.f, 1.f };
		b2PrismaticJoint * leftWheelPrismaticJoint = add_prismatic_joint(leftWheelPrismaticJointDef);

		b2RevoluteJointDef rightWheelRevoluteJointDef;
		rightWheelRevoluteJointDef.bodyA = rightWheelAxleBody;
		rightWheelRevoluteJointDef.bodyB = rightWheelBody;
		rightWheelRevoluteJointDef.enableMotor = true;
		rightWheelRevoluteJointDef.maxMotorTorque = 100000.f;
		b2RevoluteJoint * rightRevoluteWheelJoint = add_revolute_joint(rightWheelRevoluteJointDef);

		b2PrismaticJointDef rightWheelPrismaticJointDef;
		rightWheelPrismaticJointDef.bodyA = rightWheelAxleBody;
		rightWheelPrismaticJointDef.bodyB = chasisBody;
		rightWheelPrismaticJointDef.localAnchorB = rightWheelPositionOffset;
		rightWheelPrismaticJointDef.enableMotor = true;
		rightWheelPrismaticJointDef.maxMotorForce = 1000000.f;
		rightWheelPrismaticJointDef.enableLimit = true;
		rightWheelPrismaticJointDef.lowerTranslation = 0.f;
		rightWheelPrismaticJointDef.upperTranslation = 300.f;
		rightWheelPrismaticJointDef.localAxisA = { 0.f, 1.f };
		b2PrismaticJoint * rightWheelPrismaticJoint = add_prismatic_joint(rightWheelPrismaticJointDef);


		// Create the cover body and the revolute joints to open and close it

		b2Vec2 coverVerts[verticesCount] =
		{
			{0.f, 0.f},
			{0.f, 3.f},
			{50.f, 3.f},
			{50.f, 0.f}
		};

		b2BodyDef coverBodyDef;

		b2PolygonShape coverBodyShape;
		coverBodyShape.Set(coverVerts, verticesCount);

		b2FixtureDef coverFixtureDef;
		coverFixtureDef.shape = &coverBodyShape;
		coverFixtureDef.density = 1.0f;
		coverFixtureDef.restitution = 0.2f;
		coverFixtureDef.friction = 0.50f;

		b2Body* coverBody = add_body(&coverBodyDef, "cover", b2_dynamicBody);
		add_fixture_to(coverBody, &coverFixtureDef);

		b2RevoluteJointDef coverRevoluteJointDef;
		coverRevoluteJointDef.bodyA = chasisBody;
		coverRevoluteJointDef.bodyB = coverBody;
		coverRevoluteJointDef.localAnchorA = {-25.f, 50.f};
		coverRevoluteJointDef.enableMotor = true;
		coverRevoluteJointDef.motorSpeed = 5.f;
		coverRevoluteJointDef.maxMotorTorque = 1000000000.f;
		coverRevoluteJointDef.lowerAngle = to_radians(0.f);
		coverRevoluteJointDef.upperAngle = to_radians(90.f);
		coverRevoluteJointDef.enableLimit = true;
		coverJoint_ = static_cast<b2RevoluteJoint*>(add_joint(&coverRevoluteJointDef));
	}
}