#ifndef DECLARATIONS_H
#define DECLARATIONS_H

#include <Box2D/Box2D.h>
#include "SFML/Graphics.hpp"

#include <memory>
#include <vector>
#include <unordered_map>
#include <string>

#include <iostream>

using namespace sf;

namespace prz
{
	using Key = sf::Keyboard::Key;

	template<typename T>
	using PShared_ptr = std::shared_ptr<T>; // Shared pointer

	template<typename Key, typename Val>
	using PMap = std::unordered_map<Key, Val>;

	template<typename T>
	using PBuffer = std::vector<T>; // Same as vector but renamed

	using PString = std::string;

	constexpr float PI			= 3.14159f;
	constexpr float DELTA_TIME	= 0.01667f;          // ~60 fps
	
	constexpr float DEG_TO_RAD	= 0.01745f;
	constexpr float RAD_TO_DEG	= 57.29578f;

	enum EntityType : uint16_t
	{
		UNDEFINED = 0x0001,
		FLOOR = 0x0002,
		PLATFORM = 0x0004,
		VEHICLE = 0x0008,
		PARTICLE_EMITTER = 0x00010,
		FINISH = 0x00020,
		BALL = 0x00040
	};

	enum ContactState
	{
		BEGIN = 0,
		END
	};
}

#endif // !DECLARATIONS_H