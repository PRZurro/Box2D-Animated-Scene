#include "ContactListener.hpp"

namespace prz
{
	void ContactListener::BeginContact(b2Contact * contact)
	{
		contact->GetFixtureA();
	}

	void ContactListener::EndContact(b2Contact * contact)
	{
	}
}

