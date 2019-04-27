/**
 * @file Scene.hpp
 * @author Pablo Rodríguez Zurro (przuro@gmail.com)
 * @brief
 * @version 0.1
 * @date 2019-03-20
 *
 * @copyright Copyright (c) 2019
 *
 */

#ifndef BOX2D_ANIMATED_SCENE_FIRE_PARTICLE_H
#define BOX2D_ANIMATED_SCENE_FIRE_PARTICLE_H

#include "Particle.hpp"

namespace prz
{
	class FireParticle : public Particle
	{
	public:

		FireParticle():
			speed_(-1.f),
			amplitude_(-1.f),
			frequency_(-1.f),
			phase_(-1.f)
		{}

		FireParticle
		(
			const Texture & texture, 
			float posX, 
			float posY,
			float speed,
			float amplitude,
			float frequency,
			float phase,
			float scale = 1.f,
			bool isActive = false
		): 
			Particle(texture, posX, posY, scale, isActive),
			speed_(speed),
			amplitude_(amplitude),
			frequency_(frequency),
			phase_(phase)
		{}

	public:

		virtual void auxiliar_update(float deltaTime) override
		{
			positionY_ += speed_ * deltaTime;
			positionX_ += amplitude_ * std::sin((2 * PI * frequency_ * deltaTime) + phase_);

			if (scale_ >= MIN_SCALE)
			{
				scale_ -= deltaTime * SCALE_SPEED;
			}
		}

	public:

		void custom_reset(float speed, float amplitude, float frequency, float phase)
		{
			speed_ = speed;
			amplitude_ = amplitude;
			frequency_ = frequency;
			phase_ = phase;
		}

	public:

		inline void set_speed(float speed)
		{
			speed_ = speed;
		}

		inline void set_amplitude(float amplitude)
		{
			amplitude_ = amplitude;
		}

		inline void set_frequency(float frequency)
		{
			frequency_ = frequency;
		}

		inline void set_phase(float phase)
		{
			phase_ = phase;
		}

	public:

		inline float speed() const
		{
			return speed_;
		}

		inline float amplitude() const
		{
			return amplitude_;
		}

		inline float frequency() const
		{
			return frequency_;
		}

		inline float phase() const
		{
			return phase_;
		}

	private:

		float speed_;
		float amplitude_;
		float frequency_;
		float phase_;

	private:

		static constexpr float MIN_SCALE = 0.0f;
		static constexpr float SCALE_SPEED = 0.11f;
	};
}

#endif