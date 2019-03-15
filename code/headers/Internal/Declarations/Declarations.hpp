#pragma once

#include <memory>
#include <vector>
#include <unordered_map>

namespace przurro
{
	namespace prz = przurro;

	template<typename T>
	using PSptr = std::shared_ptr<T>;

	template<typename T, typename Y>
	using PMap = std::unordered_map<T, Y>;

	template<typename T>
	using PBuffer = Vector<T>; //Same as vector but renamed


	enum BodyType
	{
		Static,
		Dynamic,
		Kinematic
	};
}