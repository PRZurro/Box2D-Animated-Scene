#ifndef DECLARATIONS_H
#define DECLARATIONS_H

#include <Box2D/Box2D.h>

#include <memory>
#include <vector>
#include <unordered_map>
#include <string>

#include <iostream>



namespace prz
{
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
	

	enum EntityCategory 
	{
		Floor = 0x0001,
		Platform = 0x0002,
		Car = 0x0004,
		ParticleGenerator = 0x0008,
		Finish = 0x00010
	};

	enum ContactState
	{
		Begin = 0,
		End
	};
}

#endif // !DECLARATIONS_H