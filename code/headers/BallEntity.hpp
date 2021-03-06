/**
 * @file BallEntity.hpp
 * @author Pablo Rodr�guez Zurro (przuro@gmail.com)
 * @brief Entity to save a ball
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
	/**
	 * @brief Store a body with circular shape
	 * 
	 */
	class BallEntity : public Entity
	{
	public:

		BallEntity(float radius, Scene & scene, const PString & name, float posX, float posY, float angleDegrees = 0.f, bool active = true)
			:
			Entity(scene, name, posX, posY, angleDegrees, active, EntityType::BALL)
		{
			set_collision_filter(EntityType::BALL | EntityType::FINISH | EntityType::PARTICLE_EMITTER | EntityType::PLATFORM | EntityType::FLOOR | EntityType::VEHICLE);
			set_circles_color(Color(255, 0, 161));

			b2BodyDef bodyDef;

			b2CircleShape bodyShape;

			bodyShape.m_radius = radius;

			b2FixtureDef bodyFixture;

			bodyFixture.shape = &bodyShape;
			bodyFixture.density = 1.00f;
			bodyFixture.restitution = 0.0f;
			bodyFixture.friction = 0.50f;

			b2Body * body = add_body(&bodyDef, name_, b2_dynamicBody);
			add_fixture_to(body, &bodyFixture);
		}
	};
}// !namespace prz

#endif // !BOX2D_ANIMATED_SCENE_BALL_ENTITY_H_
