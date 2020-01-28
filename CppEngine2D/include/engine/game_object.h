#pragma once
#include <math/vector2.h>

namespace engine
{
	namespace physics
	{
		struct collision_info;
	}

	struct game_object
	{
	public:
		//member functions
		virtual void draw() const = 0;
		virtual void update(const float delta_time) = 0;
		virtual void activate();
		virtual void deactivate();

		//getter
		virtual float x() const;
		virtual float y() const;
		bool is_active() const;
		
		//setter
		virtual void set_position(float x, float y);
		virtual void set_position(my_math::vector2 position);

		//temp
		virtual void on_collision(engine::physics::collision_info* ci);

		//ctor
		game_object() = default;
		~game_object() = default;

	protected:
		bool m_is_active;
		my_math::vector2 m_position;
	};
}