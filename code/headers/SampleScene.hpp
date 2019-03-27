/**
 * @file SampleScene.hpp
 * @author Pablo Rodríguez Zurro (przuro@gmail.com)
 * @brief
 * @version 0.1
 * @date 2019-03-14
 *
 * @copyright Copyright (c) 2019
 *
 */

#ifndef BOX2D_ANIMATED_SCENE_SAMPLE_SCENE_H_
#define BOX2D_ANIMATED_SCENE_SAMPLE_SCENE_H_

#include "Scene.hpp"

namespace prz
{
	class SampleScene : public Scene
	{
	public:

		SampleScene(float posX, float posY, float worldWidth, float worldHeight);
	};
}

#endif // !BOX2D_ANIMATED_SCENE_SAMPLE_SCENE_H_
