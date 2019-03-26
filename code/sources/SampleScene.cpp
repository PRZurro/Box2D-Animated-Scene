#include "SampleScene.hpp"
#include "FloorEntity.hpp"

namespace prz
{
	SampleScene::SampleScene(float posX, float posY, float worldWidth, float worldHeight)
		:
		Scene(posX, posY, worldWidth, worldHeight)
	{
		//car->add_body()
		
		PBuffer<b2Vec2> points = 
		{
			{0, 0},
			{0, 300},
			{400, 300},
			{600,100},
			{600, 0}
		};
		add_entity(FloorEntity(points, *this, "low_floor01", 0.f, 0.f, 0.f));

		points.clear();
		points =
		{
			{0,0},
			{0, 100},
			{1000, 100},
			{1000, 0}
		};

		add_entity(FloorEntity(points, *this, "low_floor02", 600.f, 0.f, 0.f));


		//// CÍRCULO
		//{
		//	// Se crea el body a partir de una definición de sus características:

		//	b2BodyDef body_definition;

		//	body_definition.type = b2_dynamicBody;
		//	body_definition.position.Set(worldWidth_ / 2.f, worldHeight_ / 2.f);           // Posición inicial absoluta

		//	b2Body * body = physicsWorld_->CreateBody(&body_definition);

		//	// Se añande una fixture al body:

		//	b2CircleShape body_shape;

		//	body_shape.m_radius = 25.f;

		//	b2FixtureDef body_fixture;

		//	body_fixture.shape = &body_shape;
		//	body_fixture.density = 1.00f;
		//	body_fixture.restitution = 0.75f;
		//	body_fixture.friction = 0.50f;

		//	body->CreateFixture(&body_fixture);
		//}

		//// CUADRADO
		//{
		//	// Se crea el body a partir de una definición de sus características:

		//	b2BodyDef body_definition;

		//	body_definition.type = b2_dynamicBody;
		//	body_definition.position.Set(worldWidth_ / 2.f, worldHeight_ / 2.f + 200.f);   // Posición inicial absoluta
		//	body_definition.angle = 0.4f;

		//	b2Body * body = physicsWorld_->CreateBody(&body_definition);

		//	// Se añande una fixture al body:

		//	b2PolygonShape body_shape;

		//	body_shape.SetAsBox(25.f, 25.f);

		//	b2FixtureDef body_fixture;

		//	body_fixture.shape = &body_shape;
		//	body_fixture.density = 1.00f;
		//	body_fixture.restitution = 0.50f;
		//	body_fixture.friction = 0.50f;

		//	body->CreateFixture(&body_fixture);
		//}

		//// SUELO
		//{
		//	// Se crea el body a partir de una definición de sus características:

		//	b2BodyDef body_definition;

		//	body_definition.type = b2_staticBody;
		//	body_definition.position.Set(0.f, 50.f);                                       // Posición inicial absoluta
		//	body_definition.angle = 0.f;

		//	b2Body * body = physicsWorld_->CreateBody(&body_definition);

		//	// Se añande una fixture al body:

		//	b2EdgeShape body_shape;

		//	body_shape.Set(b2Vec2(0.f, 0.f), b2Vec2(worldWidth_, 0.f));                    // Coordenadas locales respecto al centro del body

		//	b2FixtureDef body_fixture;

		//	body_fixture.shape = &body_shape;

		//	body->CreateFixture(&body_fixture);
		//}
	}
}