#include "SampleScene.hpp"
#include "FloorEntity.hpp"
#include "BallEntity.hpp"
#include "CarVehicleEntity.hpp"
#include "PlatformEntity.hpp"
#include "TextureStore.hpp"
#include "BonfireParticleEmitter.hpp"

#include "internal/Utilities.hpp"

namespace prz
{
	SampleScene::SampleScene(float posX, float posY, float worldWidth, float worldHeight)
		:
		Scene(posX, posY, worldWidth, worldHeight)
	{
		TextureStore& textureStore = TextureStore::instance();

		PString fireParticlePath = "../../assets/textures/fire_particle.png";
		textureStore.load_texture(fireParticlePath);

		PShared_ptr<Entity> ball = add_entity(std::make_shared<BallEntity>(5.f, *this, "ball01", 300.f, 775.f));

		PShared_ptr<Entity> car = add_entity(std::make_shared<CarVehicleEntity>(Key::A, Key::D, 9000000.f, Key::J, Key::K, 30.f,*this, "Car", 300.f, 300.f));

		PShared_ptr<Entity> bonfire = add_entity((std::make_shared<BonfireParticleEmitter>(1000, 1.5f, 10, 0.05f, 900.f, 80.f, 1000.f, 80.f, *this, "bonfire_emitter", worldHeight)));

		PBuffer<b2Vec2> points =
		{
			{0, 0},
			{0, 300},
			{400, 300},
			{600, 100},
			{600, 0}
		};

		PShared_ptr<Entity> lowerFloor1 = add_entity(std::make_shared<FloorEntity>(points, *this, "lower_floor01", 0.f, -35.f, 0.f));

		points =
		{
			{0, 0},
			{0, 100},
			{1000, 100},
			{1000, 0}
		};

		PShared_ptr<Entity> lowerFloor2 = add_entity(std::make_shared<FloorEntity>(points, *this, "lower_floor02", 600.f, -35.f, 0.f));

		points =
		{
			{0, 0},
			{0, 50},
			{300, 50},
			{300, 0}
		};
		PShared_ptr<Entity> lowerFloor3 = add_entity(std::make_shared<FloorEntity>(points, *this, "lower_floor03", 1600.f, -85.f, 0.f));
		PShared_ptr<Entity> platformLowFloor = add_entity(std::make_shared<PlatformEntity>
		(
			lowerFloor3->get_body("lower_floor03_polygon"), points, 100.f, 885.f, 2.f, 100.f, *this, "platform_low_floor", 1600.f, 15.f, 0.f
		));

		points =
		{
			{0,0},
			{0, 50},
			{200, 50},
			{200, 0}
		};

		PShared_ptr<Entity> upperFloor1 = add_entity(std::make_shared<FloorEntity>(points, *this, "upper_floor01", 1400.f, 800.f, 0.f));

		points =
		{
			{0,0},
			{0, -50},
			{-100, -150},
			{-100, -100}
		};

		PShared_ptr<Entity> upperFloor2 = add_entity(std::make_shared<FloorEntity>(points, *this, "upper_floor02", 1400.f, 850.f, 0.f));

		points =
		{
			{0,0},
			{0, 50},
			{700, 50},
			{700, 0}
		};

		PShared_ptr<Entity> upperFloor3 = add_entity(std::make_shared<FloorEntity>(points, *this, "upper_floor03", 600.f, 700.f, 0.f));
		
		points =
		{
			{0,0},
			{0, 50},
			{200, 50},
			{200, 0}
		};

		PShared_ptr<Entity> upperFloor4 = add_entity(std::make_shared<FloorEntity>(points, *this, "upper_floor04", 400.f, 650.f, 0.f));

		PShared_ptr<Entity> platformTopFloor = add_entity(std::make_shared<PlatformEntity>
		(
			upperFloor4->get_body("upper_floor04_polygon"), points, 50.f, 300.f, 2.f, 100.f, *this, "platform_top_floor", 400.f, 700.f, 0.f
		));

		points =
		{
			{0, 0},
			{0, 50},
			{150, 50},
			{150, 0}
		};

		PShared_ptr<Entity> finishFloor1 = add_entity(std::make_shared<FloorEntity>(points, *this, "finish_l", 300.f, 850.f, to_radians(45.f)));
		PShared_ptr<Entity> finishFloor2 = add_entity(std::make_shared<FloorEntity>(points, *this, "finish_r", 300.f, 850.f, to_radians(135.f)));
		finishFloor1->set_polygons_color(Color::Green);
		finishFloor2->set_polygons_color(Color::Green);
	}
}
