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
			
			b2CircleShape circleShape;
			circleShape.m_radius = 0.5;

			// Create fixture definitions
			b2FixtureDef wheelFixtureDef;
			wheelFixtureDef.shape = &circleShape;
			wheelFixtureDef.density = 1.00f;
			wheelFixtureDef.restitution = 0.75f;
			wheelFixtureDef.friction = 0.50f;

			b2FixtureDef chasisLeftFixtureDef;
			chasisLeftFixtureDef.shape = &chasisLeftLimitShape;
			chasisLeftFixtureDef.density = 1.00f;
			chasisLeftFixtureDef.restitution = 0.75f;
			chasisLeftFixtureDef.friction = 0.50f;

			b2FixtureDef chasisRightFixtureDef;
			chasisRightFixtureDef.shape = &chasisRightLimitShape;
			chasisRightFixtureDef.density = 1.00f;
			chasisRightFixtureDef.restitution = 0.75f;
			chasisRightFixtureDef.friction = 0.50f;

			b2FixtureDef chasisBottomFixtureDef;
			chasisBottomFixtureDef.shape = &chasisBottomLimitShape;
			chasisBottomFixtureDef.density = 1.00f;
			chasisBottomFixtureDef.restitution = 0.75f;
			chasisBottomFixtureDef.friction = 0.50f;

			//Create chasis body and it's fixtures 
			b2BodyDef chasisBodyDef;
			b2Body * chasis = add_body(&chasisBodyDef, "chasis", b2_dynamicBody);

			add_fixture_to("chasis", &chasisLeftFixtureDef);
			add_fixture_to("chasis", &chasisRightFixtureDef);
			add_fixture_to("chasis", &chasisBottomFixtureDef);

			//b2WheelJointDef wheelJointDef;
		}

	};

} // !namespace prz
#endif // !BOX2D_ANIMATED_SCENE_CAR_VEHICLE_ENTITY_H_