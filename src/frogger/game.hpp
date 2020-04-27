#ifndef FROGGER_GAME
#define FROGGER_GAME

#include "../src/engine/draw_manager.hpp"
#include "../src/engine/game_clock.hpp"
#include "../src/engine/texture_manager.hpp"
#include "../src/engine/update_manager.hpp"
#include "../src/engine/physics_manager.hpp"
#include "../src/utilities/timer.hpp"
#include "../src/frogger/map.hpp"

namespace frogger
{
	class game
	{
	public:
		game();

		void start();

	private:

		void m_single_step();
		void m_load_textures();

		float m_target_fps;
		float m_frame_time;

		engine::game_clock m_game_clock;
		engine::draw_manager m_draw_manager;
		engine::update_manager m_update_manager;
		engine::physics_manager m_physics_manager;
		engine::texture_manager m_texture_manager;
		frogger::map m_game_map;
		utility::timer m_frame_timer;
	};
}

#endif