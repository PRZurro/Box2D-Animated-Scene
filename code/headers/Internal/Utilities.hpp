#ifndef BOX2D_ANIMATED_SCENE_INTERNAL_UTILITIES_H_
#define BOX2D_ANIMATED_SCENE_INTERNAL_UTILITIES_H_

#include "internal/declarations/Declarations.hpp"
#include <type_traits>
#include <random>

namespace prz
{
	// From: https://stackoverflow.com/questions/7560114/random-number-c-in-some-range
	template
	<
		typename T, //real type
		typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type
	>
	static T random(T min, T max, bool seed = false) //range : [min, max)
	{
		static bool first = true;

		if (seed || first)
		{
			std::random_device rd; // obtain a random number from hardware
			std::mt19937 eng(rd()); // seed the generator
			first = false;
		}

		std::uniform_int_distribution<> distr(min, max);

		return distr();
	}
	static float32 to_radians(float32 degrees)
	{
		float32 radians(degrees * DEG_TO_RAD);

		return radians;
	}

	static float32 to_degrees(float32 radians)
	{
		float32 degrees(radians * RAD_TO_DEG);

		return degrees;
	}
}
}

#endif // !BOX2D_ANIMATED_SCENE_INTERNAL_UTILITIES_H_