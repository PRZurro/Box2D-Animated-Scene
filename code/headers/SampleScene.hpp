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

#ifndef BOX2D_ANIMATED_SAMPLE_SCENE_MAKER_H_
#define BOX2D_ANIMATED_SAMPLE_SCENE_MAKER_H_

#include "Scene.hpp"

namespace prz
{
	class SampleScene : public Scene
	{
	public:

		SampleScene(float posX, float posY)
			:
			Scene(posX, posY)
		{}

	private:

		void create_car();
		void create_ball();
		void create_platforms();
		void create_floor();
		void create_fire();

	};
}

#endif // !BOX2D_ANIMATED_SAMPLE_SCENE_MAKER_H_
