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

#include "Internal/Declarations/Declarations.hpp"

#include <Box2D/Box2D.h>

#include <functional>

namespace prz
{
	template<class ContactHandler>
	class ContactListener : public b2ContactListener
	{
		using ContactHandlerFn = void(ContactHandler::*) (b2Contact* contact, const ContactState& state);
	
	public:

		ContactListener()
			:
			fnContactHandler_(nullptr),
			contactHandler_(nullptr)
		{}

		ContactListener(ContactHandlerFn fnContactHandler, ContactHandler* contactHandler)
			:
			fnContactHandler_(fnContactHandler),
			contactHandler_(contactHandler)
		{}

	public:

		void BeginContact(b2Contact* contact) override
		{
			if (fnContactHandler_ && contactHandler_)
			{
				//contactHandler_->*fnContactHandler_(contact, ContactState::Begin); // Non -  static functions require the bind function located in the standard library, under <functional> header
				std::bind(fnContactHandler_, contactHandler_, contact, ContactState::Begin);
			}
		}

		void EndContact(b2Contact* contact) override
		{
			if (fnContactHandler_ && contactHandler_)
			{
				std::bind(fnContactHandler_, contactHandler_, contact, ContactState::End); 
			}
		}

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
