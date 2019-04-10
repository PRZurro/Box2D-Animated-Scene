#include "SampleScene.hpp"
#include "FloorEntity.hpp"
#include "BallEntity.hpp"
#include "CarVehicleEntity.hpp"

#include "internal/Utilities.hpp"

namespace prz
{
	SampleScene::SampleScene(float posX, float posY, float worldWidth, float worldHeight)
		:
		Scene(posX, posY, worldWidth, worldHeight)
	{

		PShared_ptr<Entity> ball = add_entity(std::make_shared<Entity>(BallEntity(5.f, *this, "ball01", 300.f, 775.f)));

		PShared_ptr<Entity> car = add_entity(std::make_shared<CarVehicleEntity>(CarVehicleEntity(Key::A, Key::D, 300000000.f, Key::J, Key::K, 30.f,*this, "Car", 200.f, 400.f)));
		add_vehicle(static_cast<VehicleEntity*>(car.get()));

		PBuffer<b2Vec2> points =
		{
			{0, 0},
			{0, 300},
			{400, 300},
			{600, 100},
			{600, 0}
		};

		PShared_ptr<Entity> lowerFloor1 = add_entity(std::make_shared<Entity>(FloorEntity(points, *this, "lower_floor01", 0.f, -35.f, 0.f)));

		points =
		{
			{0, 0},
			{0, 100},
			{1000, 100},
			{1000, 0}
		};

		PShared_ptr<Entity> lowerFloor2 = add_entity(std::make_shared<Entity>(FloorEntity(points, *this, "lower_floor02", 600.f, -35.f, 0.f)));
		PShared_ptr<Entity> lowerFloor3 = add_entity(std::make_shared<Entity>(FloorEntity(points, *this, "lower_floor03", 600.f, -85.f, 0.f)));


		points =
		{
			{0,0},
			{0, 50},
			{200, 50},
			{200, 0}
		};

		PShared_ptr<Entity> upperFloor1 = add_entity(std::make_shared<Entity>(FloorEntity(points, *this, "upper_floor01", 1400.f, 800.f, 0.f)));

		points =
		{
			{0,0},
			{0, -50},
			{-100, -150},
			{-100, -100}
		};

		PShared_ptr<Entity> upperFloor2 = add_entity(std::make_shared<Entity>(FloorEntity(points, *this, "upper_floor02", 1400.f, 850.f, 0.f)));

		points =
		{
			{0,0},
			{0, 50},
			{700, 50},
			{700, 0}
		};

		PShared_ptr<Entity> upperFloor3 = add_entity(std::make_shared<Entity>(FloorEntity(points, *this, "upper_floor03", 600.f, 700.f, 0.f)));

		points =
		{
			{0,0},
			{0, 50},
			{200, 50},
			{200, 0}
		};

		PShared_ptr<Entity> upperFloor4 = add_entity(std::make_shared<Entity>(FloorEntity(points, *this, "upper_floor04", 400.f, 650.f, 0.f)));

		points =
		{
			{0, 0},
			{0, 50},
			{150, 50},
			{150, 0}
		};

		PShared_ptr<Entity> finishFloor1 = add_entity(std::make_shared<Entity>(FloorEntity(points, *this, "finish_l", 300.f, 850.f, to_radians(45.f))));
		PShared_ptr<Entity> finishFloor2 = add_entity(std::make_shared<Entity>(FloorEntity(points, *this, "finish_r", 300.f, 850.f, to_radians(135.f))));
	}
}
