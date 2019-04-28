/**
 * @file GameController.hpp
 * @author Pablo Rodr�guez Zurro (przuro@gmail.com)
 * @brief Class that controls the game flow
 * @version 0.1
 * @date 2019-03-19
 *
 * @copyright Copyright (c) 2019
 *
 */

#ifndef BOX2D_ANIMATED_SCENE_GAME_CONTROLLER_H_
#define BOX2D_ANIMATED_SCENE_GAME_CONTROLLER_H_

#include "Scene.hpp"

#include "internal/Declarations/Declarations.hpp"

#include <Box2D/Box2D.h>

namespace prz
{
	/**
	 * @brief Class that controls the game flow
	 * 
	 */
	class GameController
	{
	public:

		/**
		 * @brief Construct a new Game Controller object
		 * 
		 * @param scene 
		 */
		GameController(Scene & scene):
			scene_(scene)
		{}

	public:
		
		/**
		 * @brief Handle the collision received 
		 * 
		 * @param contact 
		 * @param state 
		 */
		void handle_contact(b2Contact* contact, const ContactState& state);

	private:

		Scene& scene_;
	};
}

#endif // !BOX2D_ANIMATED_GAME_CONTROLLER_H_
