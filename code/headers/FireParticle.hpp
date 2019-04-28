/**
 * @file FireParticle.hpp
 * @author Pablo Rodríguez Zurro (przuro@gmail.com)
 * @brief Particle with a fire texture and a sinusoidal movement
 * @version 0.1
 * @date 2019-03-20
 *
 * @copyright Copyright (c) 2019
 *
 */

#ifndef BOX2D_ANIMATED_SCENE_FIRE_PARTICLE_H_
#define BOX2D_ANIMATED_SCENE_FIRE_PARTICLE_H_

#include "Particle.hpp"

namespace prz
{
	/**
	 * @brief 
	 * 
	 */
	class FireParticle : public Particle
	{
	public:

		/**
		 * @brief Construct a new default Fire Particle object
		 * 
		 */
		FireParticle():
			speed_(-1.f),
			amplitude_(-1.f),
			frequency_(-1.f),
			phase_(-1.f)
		{}

		/**
		 * @brief Construct a new Fire Particle object
		 * 
		 * @param texture 
		 * @param posX 
		 * @param posY 
		 * @param speed 
		 * @param amplitude 
		 * @param frequency 
		 * @param phase 
		 * @param scale 
		 * @param isActive 
		 */
		FireParticle(const Texture & texture, float posX, float posY, float speed, float amplitude, float frequency, float phase, float scale = 1.f,bool isActive = false): 
			Particle(texture, posX, posY, scale, isActive),
			speed_(speed),
			amplitude_(amplitude),
			frequency_(frequency),
			phase_(phase)
		{}

	public:

		/**
		 * @brief inherited method to add the sinosoidal movement and scale over time
		 * 
		 * @param deltaTime 
		 */
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

		/**
		 * @brief custom reset of this class, to set the special members
		 * 
		 * @param speed 
		 * @param amplitude 
		 * @param frequency 
		 * @param phase 
		 */
		void custom_reset(float speed, float amplitude, float frequency, float phase)
		{
			speed_ = speed;
			amplitude_ = amplitude;
			frequency_ = frequency;
			phase_ = phase;
		}

	public:

		/**
		 * @brief Set the speed object
		 * 
		 * @param speed 
		 */
		inline void set_speed(float speed)
		{
			speed_ = speed;
		}

		/**
		 * @brief Set the amplitude object
		 * 
		 * @param amplitude 
		 */
		inline void set_amplitude(float amplitude)
		{
			amplitude_ = amplitude;
		}

		/**
		 * @brief Set the frequency object
		 * 
		 * @param frequency 
		 */
		inline void set_frequency(float frequency)
		{
			frequency_ = frequency;
		}

		/**
		 * @brief Set the phase object
		 * 
		 * @param phase 
		 */
		inline void set_phase(float phase)
		{
			phase_ = phase;
		}

	public:

		/**
		 * @brief get the speed
		 * 
		 * @return float 
		 */
		inline float speed() const
		{
			return speed_;
		}

		/**
		 * @brief get the amplitude
		 * 
		 * @return float 
		 */
		inline float amplitude() const
		{
			return amplitude_;
		}

		/**
		 * @brief get the frequency
		 * 
		 * @return float 
		 */
		inline float frequency() const
		{
			return frequency_;
		}

		/**
		 * @brief get the phase
		 * 
		 * @return float 
		 */
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
}// !namespace prz

#endif // !BOX2D_ANIMATED_SCENE_FIRE_PARTICLE_H_
