#ifndef BOX2D_ANIMATED_SCENE_INTERNAL_UTILITIES_H_
#define BOX2D_ANIMATED_SCENE_INTERNAL_UTILITIES_H_

#include "internal/declarations/Declarations.hpp"

#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <cstdlib>
#include <ctime>
#include <random>

#include <iostream>       // std::cout
#include <string>         // std::string
#include <cstddef>         // std::size_t

namespace prz
{
	template
	<
		typename T, //real type
		typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type
	>
	static T random(T min, T max, bool seed = false) //range : [min, max)
	{
		static bool first = true;

		if (first || seed)
		{
			srand(static_cast <unsigned> (time(0)));
			first = false;
		}

		T randNumber = min + T(rand()) / T(RAND_MAX / (max - min));

		return min + static_cast<T>(rand()) / static_cast<T>(RAND_MAX / (max - min));
	}

	static float to_radians(float32 degrees)
	{
		return degrees * DEG_TO_RAD;
	}

	static float to_degrees(float32 radians)
	{
		return radians * RAD_TO_DEG;
	}

	static PString split_file_name(const PString& str, const char * separator)
	{
		return str.substr(str.find_last_of(separator) + 1);
	}

	static Color lerp_rgb(Color finalColor, Color initialColor, float t)
	{
		return Color
		(
			(uint8_t)(finalColor.r + (initialColor.r - finalColor.r) * t),
			(uint8_t)(finalColor.g + (initialColor.g - finalColor.g) * t),
			(uint8_t)(finalColor.b + (initialColor.b - finalColor.b) * t),
			(uint8_t)(finalColor.a + (initialColor.a - finalColor.a) * t)
		);
	}

	static Color greyscale_color(Color colorToGreyscale)
	{
		int average = (int)((colorToGreyscale.r + colorToGreyscale.g + colorToGreyscale.b) * 0.333333f);

		return Color(average, average, average, colorToGreyscale.a);
	}
}

#endif // !BOX2D_ANIMATED_SCENE_INTERNAL_UTILITIES_H_