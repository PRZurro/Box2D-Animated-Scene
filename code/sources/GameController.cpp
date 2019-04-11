#include "GameController.hpp"
namespace prz
{
	void GameController::handle_contact(b2Contact* contact, const ContactState& state)
	{
		if (state == ContactState::BEGIN)
		{
			b2Fixture* fixtureA = contact->GetFixtureA();
			b2Fixture* fixtureB = contact->GetFixtureB();
		
			EntityType typeA = (EntityType)fixtureA->GetFilterData().categoryBits;
			EntityType typeB = (EntityType)fixtureB->GetFilterData().categoryBits;

			Entity* entityA = (Entity*)fixtureA->GetUserData();
			Entity* entityB = (Entity*)fixtureB->GetUserData();

			if (typeA != typeB)
			{
				switch (typeA)
				{
				case EntityType::BALL:
					std::cout << "el primero es bola";
					break;

				case EntityType::VEHICLE:
					std::cout << "el primero es vehiculo";
					break;

				case EntityType::FLOOR:
					std::cout << "el primero es suelo";
					break;

				case EntityType::PLATFORM:
					std::cout << "el primero es plataforma";
					break;

				}
				switch (typeB)
				{
				case EntityType::BALL:

					std::cout << " y el segundo es bola" << std::endl;
					break;

				case EntityType::VEHICLE:
					std::cout << " y el segundo es vehiculo" << std::endl;
					break;

				case EntityType::FLOOR:
					std::cout << " y el segundo es suelo" << std::endl;
					break;

				case EntityType::PLATFORM:
					std::cout << " y el segundo es platforma" << std::endl;
					break;
				}
			}
		}
		else if (state == END)
		{
			//std::cout << "end of contact..." << std::endl;
		}
	}
}