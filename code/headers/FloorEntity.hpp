/**
 * @file FloorEntity.hpp
 * @author Pablo Rodríguez Zurro (przuro@gmail.com)
 * @brief
 * @version 0.1
 * @date 2019-03-23
 *
 * @copyright Copyright (c) 2019
 *
 */

#ifndef BOX2D_ANIMATED_SCENE_FLOOR_ENTITY_H_
#define BOX2D_ANIMATED_SCENE_FLOOR_ENTITY_H_

#include "internal/declarations/Declarations.hpp"

#include "Entity.hpp"

using namespace sf;

namespace prz
{
	class FloorEntity : public Entity
	{
	public:

		FloorEntity(PBuffer<b2Vec2>& polygonPoints,Scene & scene, const PString & name, float posX, float posY, float angleDegrees, bool active = true)
			:
			Entity(scene, name, posX, posY, angleDegrees, active)
		{
			b2BodyDef bodyDef;

			b2PolygonShape bodyShape;
			bodyShape.Set(polygonPoints.data(), (int32)polygonPoints.size());

			b2FixtureDef bodyFixture;
			
			bodyFixture.shape = &bodyShape;
			bodyFixture.density = 1.00f;
			bodyFixture.restitution = 0.75f;
			bodyFixture.friction = 0.50f;

			b2Body * body = add_body(&bodyDef, name_ + "_polygon", b2_kinematicBody);
			add_fixture_to(name_ + "_polygon", &bodyFixture);
		}
	};
} // !namespace prz
#endif // !BOX2D_ANIMATED_SCENE_FLOOR_ENTITY_H_