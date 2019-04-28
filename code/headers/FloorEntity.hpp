/**
 * @file FloorEntity.hpp
 * @author Pablo Rodr�guez Zurro (przuro@gmail.com)
 * @brief Entity to save a floor (rectangular shape)
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
	/**
	 * @brief Class to save a floor entity
	 * 
	 */
	class FloorEntity : public Entity
	{
	public:

		/**
		 * @brief Construct a new Floor Entity object
		 * 
		 * @param polygonPoints 
		 * @param scene 
		 * @param name 
		 * @param posX 
		 * @param posY 
		 * @param angleDegrees 
		 * @param active 
		 */
		FloorEntity(PBuffer<b2Vec2>& polygonPoints,Scene & scene, const PString & name, float posX, float posY, float angleDegrees, bool active = true)
			:
			Entity(scene, name, posX, posY, angleDegrees, active, EntityType::FLOOR)
		{
			set_collision_filter(EntityType::BALL | EntityType::VEHICLE);

			set_polygons_color(Color(49, 0, 124));

			b2BodyDef bodyDef;

			b2PolygonShape bodyShape;
			bodyShape.Set(polygonPoints.data(), (int32)polygonPoints.size());

			b2FixtureDef bodyFixture;
			
			bodyFixture.shape = &bodyShape;
			bodyFixture.density = 1.00f;
			bodyFixture.restitution = 0.75f;
			bodyFixture.friction = 0.50f;

			b2Body * body = add_body(&bodyDef, name_ + "_polygon", b2_kinematicBody);
			add_fixture_to(body, &bodyFixture);
		}
	};
} // !namespace prz

#endif // !BOX2D_ANIMATED_SCENE_FLOOR_ENTITY_H_
