#ifndef BOX2D_ANIMATED_INTERNAL_EXTERNAL_LIBRARIES_UTILITIES_H_
#define BOX2D_ANIMATED_INTERNAL_EXTERNAL_LIBRARIES_UTILITIES_H_

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

using namespace sf;

namespace prz
{
	static inline Vector2f box2d_position_to_sfml_position(const b2Vec2 & box2d_position, float window_height)
	{
		return Vector2f(box2d_position.x, window_height - box2d_position.y);
	}
}



#endif // !BOX2D_ANIMATED_INTERNAL_EXTERNAL_LIBRARIES_UTILITIES_H_