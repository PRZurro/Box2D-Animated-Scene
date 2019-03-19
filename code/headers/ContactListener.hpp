/**
 * @file Scene.hpp
 * @author Pablo Rodríguez Zurro (przuro@gmail.com)
 * @brief
 * @version 0.1
 * @date 2019-03-18
 *
 * @copyright Copyright (c) 2019
 *
 */

#ifndef BOX2D_ANIMATED_SCENE_CONTACT_LISTENER_H_
#define BOX2D_ANIMATED_SCENE_CONTACT_LISTENER_H_

#include <Box2D/Box2D.h>

namespace prz
{
	template<class ContactHandler>
	class ContactListener : public b2ContactListener
	{
		typedef void (*ContactHandler::ContactHandlerFn) (b2Contact* contact, const ContactState& state);

	public:

		ContactListener()
			:
			fnContactHandler_(nullptr),
			contactHandler_(nullptr)

		{
		}
		ContactListener(ContactHandlerFn fnContactHandler, ContactHandler* contactHandler)
			:
			fnContactHandler_(fnContactHandler),
			contactHandler_(contactHandler)
		{
		}

	public:

		void BeginContact(b2Contact* contact) override;
		void EndContact(b2Contact* contact) override;

	public:

		void set_contact_handler_fn(ContactHandlerFn contactHandler)
		{
			fnContactHandler_ = contactHandler;
		}

		void set_contact_handler_obj(ContactHandler* handler)
		{
			contactHandler_ = handler;
		}

	private:
		
		ContactHandlerFn fnContactHandler_;
		ContactHandler* contactHandler_;
	};
}


#endif // !BOX2D_ANIMATED_SCENE_CONTACT_LISTENER_H_
