#ifndef BOX2D_ANIMATED_SCENE_INPUT_LISTENER_H_
#define BOX2D_ANIMATED_SCENE_INPUT_LISTENER_H_

#include "Internal/Declarations/Declarations.hpp"
#include <SFML/Graphics.hpp>

using namespace sf;

namespace prz
{
	class InputListener
	{
	public:

		InputListener()
		{}

	public:

		void update(Event& event)
		{
			if (event.type == Event::KeyPressed)
			{
				keysPressed[event.key.code] = 'a';
			}
		}

		void clear_keys()
		{
			keysPressed.clear();
		}

	public:

		bool is_key_pressed(const Keyboard::Key& key) const
		{
			if (keysPressed.find(key) != keysPressed.end())
				return true;

			return false;
		}

	private:

		PMap< Keyboard::Key, char > keysPressed;

	};

}
#endif //!BOX2D_ANIMATED_SCENE_INPUT_LISTENER_H_