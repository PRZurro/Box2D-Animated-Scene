#include "GameController.hpp"
#include "Entity.hpp"
#include "CarVehicleEntity.hpp"
#include "PlatformEntity.hpp"

namespace prz
{
	void GameController::handle_contact(b2Contact* contact, const ContactState& state)
	{

		b2Fixture* fixtureA = contact->GetFixtureA();
		b2Fixture* fixtureB = contact->GetFixtureB();

		EntityType typeA = (EntityType)fixtureA->GetFilterData().categoryBits;
		EntityType typeB = (EntityType)fixtureB->GetFilterData().categoryBits;

		Entity* entityA = (Entity*)fixtureA->GetUserData();
		Entity* entityB = (Entity*)fixtureB->GetUserData();

		CarVehicleEntity* vehicle = nullptr;
		PlatformEntity* platform = nullptr;

		if (typeA == VEHICLE)
		{
			vehicle = static_cast<CarVehicleEntity*>(entityA);
		}
		else if (typeB == VEHICLE)
		{
			vehicle = static_cast<CarVehicleEntity*>(entityB);
		}

		if (typeA == PLATFORM)
		{
			platform = static_cast<PlatformEntity*>(entityA);
		}
		else if (typeB == PLATFORM)
		{
			platform = static_cast<PlatformEntity*>(entityB);
		}

		bool ball = false;
		bool fire = false;

		if (typeA == BALL)
		{
			ball = true;
		}
		if (typeB == BALL)
		{
			ball = true;
		}
		if (typeA == PARTICLE_EMITTER)
		{
			fire = true;
		}
		if (typeB == PARTICLE_EMITTER)
		{
			fire = true;
		}

		if (state == ContactState::BEGIN)
		{
			if (ball && fire)
			{
				std::cout << "tiene que resetear" << std::endl;
 				scene_.must_reset();
			}
			else if (vehicle && platform)
			{
				platform->start_timer();
			}
		}
		else if (state == END)
		{
			if (vehicle && platform)
			{
				platform->end_timer();
			}
		}
	}
}