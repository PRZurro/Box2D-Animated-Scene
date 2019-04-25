#include "Scene.hpp"
#include "internal/ExternalLibrariesUtilities.hpp"
#include "VehicleEntity.hpp"

namespace prz
{
	void Scene::update(float deltaTime)
	{
		if (InputManager::instance().is_key_pressed(Key::R))
		{
			reset();
		}

		for (auto& entity : entities_)
		{
			entity.second->update(deltaTime);
		}

		physicsWorld_->Step(deltaTime, 8, 4);

		auxiliar_update(deltaTime);

	}
	void Scene::render(RenderWindow& window)
	{
		for (auto& entity : entities_)
		{
			entity.second->render(window);
		}
	}
}

