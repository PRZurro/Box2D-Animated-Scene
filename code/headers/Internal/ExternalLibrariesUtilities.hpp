#ifndef BOX2D_ANIMATED_SCENE_INTERNAL_EXTERNAL_LIBRARIES_UTILITIES_H_
#define BOX2D_ANIMATED_SCENE_INTERNAL_EXTERNAL_LIBRARIES_UTILITIES_H_

#include <SFML/Graphics.hpp>

#include <Box2D/Box2D.h>

using namespace sf;

namespace prz
{

	/** En Box2D las coordenadas Y crecen hacia arriba y en SFML crecen hacia abajo desde el borde superior.
	 ** Esta función se encarga de convertir el sistema de coordenadas para que la escena no se vea invertida.
	 **/

	static Vector2f box2d_position_to_sfml_position(const b2Vec2 & box2d_position, float window_height, float scale = 1.f)
	{
		return Vector2f(box2d_position.x * scale, (window_height - box2d_position.y) * scale);
	}

}
#endif // !BOX2D_ANIMATED_SCENE_INTERNAL_EXTERNAL_LIBRARIES_UTILITIES_H_