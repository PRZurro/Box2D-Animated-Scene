#include "BonfireParticleEmitter.hpp"

//namespace prz
//{
//	void BonfireParticleEmitter::reset_fire_particle(FireParticle & fireParticle)
//	{
//		float posX = random<float>(segmentPointAX, segmentPointBX);
//		float posY = (segmentPointBY - segmentPointAY) / (segmentPointBX - segmentPointAX) * (posX - segmentPointAX) + segmentPointAY;
//
//		fireParticle.reset(posX, posY, true);
//
//		fireParticle.custom_reset
//		(
//			random<float>(MIN_SPEED, MAX_SPEED, true),
//			random<float>(MIN_AMPLITUDE, MAX_AMPLITUDE),
//			random<float>(MIN_FREQUENCY, MAX_FREQUENCY),
//			random<float>(MIN_PHASE, MAX_PHASE)
//		);
//	}
//}