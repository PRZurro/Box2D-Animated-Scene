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
#include "VehicleEntity.hpp"

namespace prz
{
	class CarVehicleEntity : public VehicleEntity
	{
	public:

		CarVehicleEntity(Key leftKey, Key rightKey, float speed, Scene & scene, const PString & name, float posX, float posY, float angleDegrees = 0.f, bool active = true)
			:
			VehicleEntity(leftKey, rightKey, speed, scene, name, posX, posY, angleDegrees, active)
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
			chasisLeftFixtureDef.density = 10.00f;
			chasisLeftFixtureDef.restitution = 0.2f;
			chasisLeftFixtureDef.friction = 0.50f;

			b2FixtureDef chasisRightFixtureDef;
			chasisRightFixtureDef.shape = &chasisRightLimitShape;
			chasisRightFixtureDef.density = 10.00f;
			chasisRightFixtureDef.restitution = 0.2f;
			chasisRightFixtureDef.friction = 0.50f;

			b2FixtureDef chasisBottomFixtureDef;
			chasisBottomFixtureDef.shape = &chasisBottomLimitShape;
			chasisBottomFixtureDef.density = 10.00f;
			chasisBottomFixtureDef.restitution = 0.75f;
			chasisBottomFixtureDef.friction = 0.50f;

			//Create chasis body and it's fixtures 
			b2BodyDef chasisBodyDef;
			b2Body * chasis = add_body(&chasisBodyDef, "chasis", b2_dynamicBody);

			add_fixture_to("chasis", &chasisLeftFixtureDef);
			add_fixture_to("chasis", &chasisRightFixtureDef);
			add_fixture_to("chasis", &chasisBottomFixtureDef);

			///////////////////////////////////WHEELS CREATION////////////////////////////////////
			// Left wheel
			b2Vec2 leftWheelPositionOffset(-30.5f, -0.5f);

			b2BodyDef leftWheelBodyDef;

			b2CircleShape leftWheelBodyShape;
			leftWheelBodyShape.m_radius = 10;

			b2FixtureDef leftWheelBodyFixture;

			leftWheelBodyFixture.shape = &leftWheelBodyShape;
			leftWheelBodyFixture.density = 5.0f;
			leftWheelBodyFixture.restitution = 0.75f;
			leftWheelBodyFixture.friction = 0.50f;

			b2Body * leftWheelBody = add_body(&leftWheelBodyDef, name_, b2_dynamicBody);
			leftWheelBody->CreateFixture(&leftWheelBodyFixture);

			b2WheelJointDef leftWheelJointDef;
			leftWheelJointDef.enableMotor = false;
			leftWheelJointDef.bodyA = chasis;
			leftWheelJointDef.bodyB = leftWheelBody;
			leftWheelJointDef.dampingRatio = 0.7f;
			leftWheelJointDef.frequencyHz = 4.0f;

			leftWheelJointDef.localAnchorA = leftWheelPositionOffset;

			leftWheelBody->SetTransform(leftWheelBody->GetPosition() + leftWheelPositionOffset, leftWheelBody->GetAngle());

			b2WheelJoint * leftWheelJoint = add_wheel_joint(leftWheelJointDef); 

			// Right wheel

			b2Vec2 rightWheelPositionOffset(30.5f, 0.5f);

			b2BodyDef rightWheelBodyDef;

			b2CircleShape rightWheelBodyShape;
			rightWheelBodyShape.m_radius = 10;

			b2FixtureDef rightWheelBodyFixture;

			rightWheelBodyFixture.shape = &rightWheelBodyShape;
			rightWheelBodyFixture.density = 5.0f;
			rightWheelBodyFixture.restitution = 0.75f;
			rightWheelBodyFixture.friction = 0.50f;

			b2Body * rightWheelBody = add_body(&rightWheelBodyDef, name_, b2_dynamicBody);
			rightWheelBody->CreateFixture(&rightWheelBodyFixture);

			b2WheelJointDef rightWheelJointDef;
			rightWheelJointDef.enableMotor = false;
			rightWheelJointDef.bodyA = chasis;
			rightWheelJointDef.bodyB = rightWheelBody;
			rightWheelJointDef.dampingRatio = 0.7f;
			rightWheelJointDef.frequencyHz = 4.0f;

			rightWheelJointDef.localAnchorA = rightWheelPositionOffset;

			rightWheelBody->SetTransform(rightWheelBody->GetPosition() + rightWheelPositionOffset, rightWheelBody->GetAngle());

			b2WheelJoint * rightWheelJoint = add_wheel_joint(rightWheelJointDef);
		}
	};

} // !namespace prz
#endif // !BOX2D_ANIMATED_SCENE_CAR_VEHICLE_ENTITY_H_
