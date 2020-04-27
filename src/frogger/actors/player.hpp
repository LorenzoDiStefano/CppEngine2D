#ifndef FROGGER_PLAYER
#define FROGGER_PLAYER

#include "../src/engine/game_object.hpp"
#include "../src/engine/physics/collision_info.hpp"
#include "../src/engine/draw_manager.hpp"
#include "../src/engine/physics/rigid_body.hpp"
#include "../src/frogger/actors/obstacle.hpp"

namespace frogger
{
	struct player : public engine::game_object 
	{
		//member functions
		void read_input(const float dt);
		void respawn();
		void set_position(float x, float y) override;
		void on_collision(engine::physics::collision_info* ci) override;

		void update(const float dt) override;
		void draw() const override;

		//ctor
		player(engine::draw_manager& fm, engine::gfx::image_info* img_info);
		player() = delete;
		~player() = default;

		my_math::vector2 spawn_point;
		engine::physics::rigid_body rigid_body;

	private:

		mutable engine::gfx::sprite m_sprite;
		
		//input vars
		int m_last_frame_input;
		my_math::vector2 m_input_direction;

		//wood log vars
		obstacle* m_log;
		bool m_on_water;
	};
}

#endif