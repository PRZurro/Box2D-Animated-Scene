/**
 * @file SampleScene.hpp
 * @author Pablo Rodr�guez Zurro (przuro@gmail.com)
 * @brief Sample constructed scene 
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
	/**
	 * @brief Sample scene, as an example of how construct one 
	 * 
	 */
	class SampleScene : public Scene
	{
	public:

		/**
		 * @brief Construct a new Sample Scene
		 * 
		 * @param posX 
		 * @param posY 
		 * @param worldWidth 
		 * @param worldHeight 
		 */
		SampleScene(float posX, float posY, float worldWidth, float worldHeight);
	};
}

#endif // !BOX2D_ANIMATED_SCENE_SAMPLE_SCENE_H_
