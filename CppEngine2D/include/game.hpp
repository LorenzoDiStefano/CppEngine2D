#ifndef FROGGER_GAME
#define FROGGER_GAME

#include <engine/draw_manager.hpp>
#include <engine/game_clock.hpp>
#include <engine/texture_mananger.hpp>
#include <engine/update_manager.hpp>
#include <engine/physics_manager.hpp>
#include <utility/timer.hpp>
#include <frogger/map.hpp>

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