/**
 * @file PlatformEntity.hpp
 * @author Pablo Rodríguez Zurro (przuro@gmail.com)
 * @brief
 * @version 0.1
 * @date 2019-04-09
 *
 * @copyright Copyright (c) 2019
 *
 */

#ifndef BOX2D_ANIMATED_SCENE_PLATFORM_ENTITY_H_
#define BOX2D_ANIMATED_SCENE_PLATFORM_ENTITY_H_

#include "internal/declarations/Declarations.hpp"
#include "internal/Utilities.hpp"

#include "FloorEntity.hpp"

namespace prz
{
	class PlatformEntity : public FloorEntity
	{
	public:

		PlatformEntity(b2Body* supportBody, PBuffer<b2Vec2>& polygonPoints, float lowerTranslation, float upperTranslation, float timerTime, float motorSpeed, Scene& scene, const PString& name, float posX, float posY, float angleDegrees = 0.f, bool active = true);
	
	public:

		virtual void update(float deltaTime) override;
		
	public:

		void start_timer()
		{
			addEndContactTime_ = false;
			addStartContactTime_ = true;
			timeSinceEndContact_ = 0.f;
		}

		void end_timer()
		{
			addStartContactTime_ = false;
			addEndContactTime_ = true;
		}
	
	private:

		b2PrismaticJoint* prismaticJoint_;

		float motorSpeed_;

		bool addStartContactTime_;
		bool addEndContactTime_;

		float timeSinceStartContact_;
		float timeSinceEndContact_;
		float timerTime_;
	};
} // !namespace prz
#endif // !BOX2D_ANIMATED_SCENE_PLATFORM_ENTITY_H_
