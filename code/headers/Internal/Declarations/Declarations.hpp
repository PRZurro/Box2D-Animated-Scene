#pragma once

#include <memory>
#include <vector>
#include <unordered_map>
#include <string>

namespace prz
{
	template<typename T>
	using PSptr = std::shared_ptr<T>; // Shared pointer

	template<typename T, typename Y>
	using PMap = std::unordered_map<T, Y>;

	template<typename T>
	using PBuffer = std::vector<T>; // Same as vector but renamed

	using PString = std::string;

	enum BodyType
	{
		Static = 0,
		Kinematic,
		Dynamic
	};
}