/**
 * @file BallEntity.hpp
 * @author Pablo Rodríguez Zurro (przuro@gmail.com)
 * @brief
 * @version 0.1
 * @date 2019-03-23
 *
 * @copyright Copyright (c) 2019
 *
 */

#ifndef BOX2D_ANIMATED_SCENE_BALL_ENTITY_H_
#define BOX2D_ANIMATED_SCENE_BALL_ENTITY_H_

#include "internal/declarations/Declarations.hpp"
#include "Entity.hpp"

namespace prz
{
	class BallEntity : public Entity
	{
	public:

		BallEntity(float radius, Scene & scene, const PString & name, float posX, float posY, float angleDegrees = 0.f, bool active = true)
			:
			Entity(scene, name, posX, posY, angleDegrees, active)
		{
			b2BodyDef bodyDef;

			b2CircleShape bodyShape;

			bodyShape.m_radius = radius;

			b2FixtureDef bodyFixture;

			bodyFixture.shape = &bodyShape;
			bodyFixture.density = 300.00f;
			bodyFixture.restitution = 0.0f;
			bodyFixture.friction = 0.50f;

			b2Body * body = add_body(&bodyDef, name_, b2_dynamicBody);
			body->CreateFixture(&bodyFixture);
		}
	};
}

#endif // !BOX2D_ANIMATED_SCENE_BALL_ENTITY_H_