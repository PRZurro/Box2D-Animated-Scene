/**
 * @file PlatformEntity.hpp
 * @author Pablo Rodr�guez Zurro (przuro@gmail.com)
 * @brief Class to save a platform entity, a floor entity with capacity to move 
 * @version 0.1
 * @date 2019-04-09
 *
 * @copyright Copyright (c) 2019
 *
 */

#ifndef BOX2D_ANIMATED_SCENE_PLATFORM_ENTITY_H_
#define BOX2D_ANIMATED_SCENE_PLATFORM_ENTITY_H_

#include "FloorEntity.hpp"

#include "internal/declarations/Declarations.hpp"
#include "internal/Utilities.hpp"

namespace prz
{
	/**
	 * @brief Class to save a platform entity, a floor entity with capacity to move by its prismatic joint
	 * 
	 */
	class PlatformEntity : public FloorEntity
	{
	public:

		/**
		 * @brief Construct a new Platform Entity object
		 * 
		 * @param supportBody 
		 * @param polygonPoints 
		 * @param lowerTranslation 
		 * @param upperTranslation 
		 * @param timerTime 
		 * @param motorSpeed 
		 * @param scene 
		 * @param name 
		 * @param posX 
		 * @param posY 
		 * @param angleDegrees 
		 * @param active 
		 */
		PlatformEntity(b2Body* supportBody, PBuffer<b2Vec2>& polygonPoints, float lowerTranslation, float upperTranslation, float timerTime, float motorSpeed, Scene& scene, const PString& name, float posX, float posY, float angleDegrees = 0.f, bool active = true);
	
	public:

		/**
		 * @brief Method to move the platform's prismatic joint  
		 * 
		 * @param deltaTime 
		 */
		virtual void auxiliar_update(float deltaTime) override;
		
	public:

		/**
		 * @brief start the timer
		 * 
		 */
		void start_timer()
		{
			addEndContactTime_ = false;
			addStartContactTime_ = true;
			timeSinceEndContact_ = 0.f;
		}

		/**
		 * @brief end the timer
		 * 
		 */
		void end_timer()
		{
			addStartContactTime_ = false;
			addEndContactTime_ = true;
		}
	
	private:

		b2PrismaticJoint* prismaticJoint_;

	private:

		float motorSpeed_;

	private:

		bool addStartContactTime_;
		bool addEndContactTime_;

	private:
	
		float timeSinceStartContact_;
		float timeSinceEndContact_;
		float timerTime_;
	};
} // !namespace prz
#endif // !BOX2D_ANIMATED_SCENE_PLATFORM_ENTITY_H_
