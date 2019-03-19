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
	class ContactListener : public b2ContactListener
	{
	public:

		void BeginContact(b2Contact* contact) override;
		void EndContact(b2Contact* contact) override;

	};
}


#endif // !BOX2D_ANIMATED_SCENE_CONTACT_LISTENER_H_
