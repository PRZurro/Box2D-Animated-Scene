/**
 * @file ContactListener.hpp
 * @author Pablo Rodríguez Zurro (przuro@gmail.com)
 * @brief Listener of Box2D collisions that delegates the collision detection to an unknown method member from an unknown object 
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
	/**
	 * @brief Class template to manage Box2D collision detection 
	 * 
	 * @tparam ContactHandler 
	 */
	template<class ContactHandler>
	class ContactListener : public b2ContactListener
	{
		// Delegate function
		using ContactHandlerFn = void(ContactHandler::*) (b2Contact* contact, const ContactState& state);

	public:

		/**
		 * @brief return an static instance object of this class
		 * 
		 * @return ContactListener<ContactHandler>& 
		 */
		static ContactListener<ContactHandler>& instance()
		{
			static ContactListener<ContactHandler> instance;
			return instance;
		}

	public:

		/**
		 * @brief Overrided method belonging to Box2D libraries. Capture the begin of a collision
		 * 
		 * @param contact 
		 */
		void BeginContact(b2Contact* contact) override
		{
			if (fnContactHandler_ && contactHandler_)
			{
				//std::cout << "Contact began \n" << std::endl;

				/*std::function<void()> handlerCall = std::bind(fnContactHandler_, contactHandler_, contact, ContactState::Begin);
				handlerCall();*/ // Another way to call a generic function from generic object

				(contactHandler_->*fnContactHandler_)(contact, ContactState::BEGIN);
			}
		}

		/**
		 * @brief Overrided method belonging to Box2D libraries. Capture the end of a collision
		 * 
		 * @param contact 
		 */
		void EndContact(b2Contact* contact) override
		{
			if (fnContactHandler_ && contactHandler_)
			{
				//std::cout << "Contact finished \n" << std::endl;
				
				(contactHandler_->*fnContactHandler_)(contact, ContactState::END);
			}
		}

	public:

		/**
		 * @brief Method to set all members of this class.
		 * 
		 * @param contactHandler, delegate function
		 * @param handlerObj, object that store the delegate function
		 */
		void set(ContactHandlerFn contactHandler, ContactHandler* handlerObj)
		{
			set_contact_handler_fn(contactHandler);
			set_contact_handler_obj(handlerObj);
		}

		/**
		 * @brief Set the delegate function
		 * 
		 * @param fnContactHandler 
		 */
		void set_contact_handler_fn(ContactHandlerFn fnContactHandler)
		{
			fnContactHandler_ = fnContactHandler;
		}

		/**
		 * @brief Set the contact handler object
		 * 
		 * @param handlerObj 
		 */
		void set_contact_handler_obj(ContactHandler* handlerObj)
		{
			contactHandler_ = handlerObj;
		}

	private:

		/**
		 * @brief Construct a new Contact Listener object. Private to avoid instantiation
		 * 
		 */
		ContactListener()
			:
			fnContactHandler_(nullptr),
			contactHandler_(nullptr)
		{}

	private:
		
		ContactHandlerFn fnContactHandler_;
		ContactHandler* contactHandler_;
	};
} // !namespace prz

#endif // !BOX2D_ANIMATED_SCENE_CONTACT_LISTENER_H_
