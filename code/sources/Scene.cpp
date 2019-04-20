#include "Scene.hpp"
#include "internal/ExternalLibrariesUtilities.hpp"
#include "VehicleEntity.hpp"

namespace prz
{
	void Scene::update(float deltaTime)
	{
		for (auto& entity : entities_)
		{
			entity.second->update(deltaTime);
		}

		physicsWorld_->Step(deltaTime, 8, 4);

	}
	void Scene::render(RenderWindow& window)
	{
		for (auto& entity : entities_)
		{
			entity.second->render(window);
		}
	}
}

