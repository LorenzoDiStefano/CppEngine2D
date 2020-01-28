#pragma once

#include <engine/draw_manager.h>
#include <engine/game_clock.h>
#include <engine/texture_mananger.h>
#include <engine/update_manager.h>
#include <engine/physics_manager.h>
#include <utility/timer.h>
#include <frogger/map.h>

namespace frogger
{
	class game
	{
	public:
		game();
		~game();

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
		utilities::timer m_frame_timer;
	};
}