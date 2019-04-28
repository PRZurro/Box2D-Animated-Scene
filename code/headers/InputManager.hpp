/**
 * @file InputManager.hpp
 * @author Pablo Rodríguez
 * @brief Manage the keyboard input
 * @version 0.1
 * @date 2019-03-23
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef BOX2D_ANIMATED_SCENE_INPUT_LISTENER_H_
#define BOX2D_ANIMATED_SCENE_INPUT_LISTENER_H_

#include "Internal/Declarations/Declarations.hpp"

#include <SFML/Graphics.hpp>

using namespace sf;

namespace prz
{
	class InputManager
	{
	public:

		/**
		 * @brief Get an static instance object of this class
		 * 
		 * @return InputManager& 
		 */
		static InputManager & instance()
		{
			static InputManager instance;
			return instance;
		}

	public:
		
		/**
		 * @brief Update the keyboard state with the input event
		 * 
		 * @param event 
		 */
		void update(Event& event)
		{
			if (event.type == Event::KeyPressed)
			{
				keysPressed_[event.key.code] = true;
			}
			if (event.type == Event::KeyReleased)
			{
				keysPressed_[event.key.code] = false;
			}
		}
	public:

		/**
		 * @brief Get the state of a key
		 * 
		 * @param key 
		 * @return true 
		 * @return false 
		 */
		bool is_key_pressed(const Key& key) const
		{
			return keysPressed_.count(key) == 1 && keysPressed_.at(key) == true;
		}

	private:

		/**
		 * @brief Construct a new Input Manager object, private to avoid undesired instantiation 
		 * 
		 */
		InputManager()
		{}

	private:

		PMap< Key, bool > keysPressed_;

	};
}
#endif //!BOX2D_ANIMATED_SCENE_INPUT_LISTENER_H_