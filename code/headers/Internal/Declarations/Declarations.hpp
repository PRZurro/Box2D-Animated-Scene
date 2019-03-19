#ifndef DECLARATIONS_H
#define DECLARATIONS_H

#include <memory>
#include <vector>
#include <unordered_map>
#include <string>

#include <Box2D/Box2D.h>

namespace prz
{
	template<typename T>
	using PShared_ptr = std::shared_ptr<T>; // Shared pointer

	template<typename Key, typename Val>
	using PMap = std::unordered_map<Key, Val>;

	template<typename T>
	using PBuffer = std::vector<T>; // Same as vector but renamed

	using PString = std::string;

	using PBodyType = b2BodyType;
	using PTransform = b2Transform;

	#define DEG_TO_RAD 0.0174533f
	#define RAD_TO_DEG 57.295779513f

	enum EntityCategory {
		Floor = 0x0001,
		Platform = 0x0002,
		Car = 0x0004,
		ParticleGenerator = 0x0008,
		Finish = 0x00010
	};
}

#endif // !DECLARATIONS_H