#include "SampleScene.hpp"
#include "FloorEntity.hpp"
#include "BallEntity.hpp"

#include "internal/Utilities.hpp"

namespace prz
{
	SampleScene::SampleScene(float posX, float posY, float worldWidth, float worldHeight)
		:
		Scene(posX, posY, worldWidth, worldHeight)
	{
		PBuffer<b2Vec2> points = 
		{
			{0, 0},
			{0, 300},
			{400, 300},
			{600,100},
			{600, 0}
		};
		add_entity(std::make_shared<Entity>(FloorEntity(points, *this, "lower_floor01", 0.f, -35.f, 0.f)));

		points.clear();
		points =
		{
			{0,0},
			{0, 100},
			{1000, 100},
			{1000, 0}
		};

		add_entity(std::make_shared<Entity>(FloorEntity(points, *this, "lower_floor02", 600.f, -35.f, 0.f)));

		points.clear();
		points =
		{
			{0,0},
			{0, 50},
			{1000, 50},
			{1000, 0}
		};

		add_entity(std::make_shared<Entity>(FloorEntity(points, *this, "upper_floor01", 600.f, 650.f, 0.f)));

		points =
		{
			{0, 0},
			{0, 50},
			{150, 50},
			{150, 0}
		};

		add_entity(std::make_shared<Entity>(FloorEntity(points, *this, "finish_l", 300.f, 850.f, to_radians(45.f))));
		add_entity(std::make_shared<Entity>(FloorEntity(points, *this, "finish_r", 300.f, 850.f, to_radians(135.f))));

		add_entity(std::make_shared<Entity>(BallEntity(12.f, *this, "ball01", 300.f, 750.f)));
	}
}