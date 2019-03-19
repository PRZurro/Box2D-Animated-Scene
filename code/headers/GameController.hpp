/**
 * @file Scene.hpp
 * @author Pablo Rodríguez Zurro (przuro@gmail.com)
 * @brief
 * @version 0.1
 * @date 2019-03-19
 *
 * @copyright Copyright (c) 2019
 *
 */

#ifndef BOX2D_ANIMATED_SCENE_GAME_CONTROLLER_H_
#define BOX2D_ANIMATED_SCENE_GAME_CONTROLLER_H_

#include "Scene.hpp"
#include "ContactListener.hpp"

#include <Box2D/Box2D.h>

namespace prz
{
	class GameController
	{
	public:

		GameController(Scene & scene)
		{}

	public:
		
		void handle_contact(b2Contact* contact, const ContactState& state);
	};

}


#endif // !BOX2D_ANIMATED_GAME_CONTROLLER_H_
