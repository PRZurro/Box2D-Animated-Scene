#ifndef DECLARATIONS_H
#define DECLARATIONS_H

#include <memory>
#include <vector>
#include <unordered_map>
#include <string>

namespace prz
{
	template<typename T>
	using PShared_ptr = std::shared_ptr<T>; // Shared pointer

	template<typename Key, typename Val>
	using PMap = std::unordered_map<Key, Val>;

	template<typename T>
	using PBuffer = std::vector<T>; // Same as vector but renamed

	using PString = std::string;

	enum BodyType
	{
		Static = 0,
		Kinematic,
		Dynamic
	};

	enum EntityCategory {
		Floor = 0,
		Platform,
		Car,
		ParticleGenerator,
		Finish
	};

}


#endif // !DECLARATIONS_H

