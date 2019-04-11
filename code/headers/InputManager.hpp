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

		static InputManager & instance()
		{
			static InputManager instance;
			return instance;
		}

	public:

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

		bool is_key_pressed(const Key& key) const
		{
			return keysPressed_.count(key) == 1 && keysPressed_.at(key) == true;
		}

	private:

		InputManager()
		{}

	private:

		PMap< Key , bool > keysPressed_;

	};
}
#endif //!BOX2D_ANIMATED_SCENE_INPUT_LISTENER_H_