#include "ContactListener.hpp"

namespace prz
{
	template<class ContactHandler>
	void ContactListener<ContactHandler>::BeginContact(b2Contact * contact)
	{
		if (fnContactHandler_ && contactHandler_)
		{

		}
	}

	template<class ContactHandler>
	void ContactListener<ContactHandler>::EndContact(b2Contact * contact)
	{
		if (fnContactHandler_ && contactHandler_)
		{
			contactHandler_->*fnContactHandler_(contact->GetFixtureA(), contact->GetFixtureB());
		}
	}
}

