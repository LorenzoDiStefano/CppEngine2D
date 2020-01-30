#include <game.h>
#include <frogger/actors/player.h>
#include <frogger/actors/obstacle.h>
#include <engine/event.h>
#include <thread>
#include <chrono>

namespace frogger
{
	game::game() :
		m_target_fps{ 60.0f },
		m_frame_time{ 1.0f / m_target_fps },
		m_frame_timer{ utility::timer(true, m_frame_time) }
	{
		m_frame_timer.callback = std::bind(&game::m_single_step, this);
		//not working here
		//m_frame_timer.callback = [this]() { m_single_step(); };
	}

	void game::m_single_step()
	{
		engine::event my_event;

		while (my_event.poll_event())
		{
			if (my_event.get_type() == (unsigned int)engine::event::TYPE::QUIT)
			{
				m_draw_manager.quit();
				exit(1);
			}
		}

		m_physics_manager.update(m_frame_time);
		m_physics_manager.check_collisions();
		m_update_manager.update(m_frame_time);
		m_draw_manager.draw_scene();

		//printf("rendering, %f interval passed\n", m_frame_timer.get_interval());
	}

	void game::start()
	{
		srand(time(NULL));

		m_texture_manager.set_renderer(&m_draw_manager.renderer);
		m_load_textures();
		m_game_map.init(m_draw_manager, &m_texture_manager, m_physics_manager, m_update_manager);
		m_frame_timer.start();

		frogger::player player = frogger::player(m_draw_manager, &m_texture_manager.textures[0]);
		m_update_manager.add_game_object(player);
		m_physics_manager.add_rigid_body(&player.rigid_body);

		float now;
		long long missing_time;
		while (true)
		{
			now = m_game_clock.get_now();
			m_frame_timer.tick(now);

			//reducing cpu usage
			//get a fraction of the missing time before next frame
			missing_time = m_frame_timer.missing_time() * 300;
			//wait for a fraction of the missing time, may have problems with low duration sleeps
			std::this_thread::sleep_for(std::chrono::milliseconds(missing_time));
		}
	}

	void game::m_load_textures()
	{
		const char* paths[8];
		paths[0] = "assets/frogger/frog.png";
		paths[1] = "assets/frogger/ph_road_bg.png";
		paths[2] = "assets/frogger/ph_water_bg.png";
		paths[3] = "assets/frogger/ph_victory_bg.png";
		paths[4] = "assets/frogger/car.png";
		paths[5] = "assets/frogger/car_flip.png";
		paths[6] = "assets/frogger/log.png";
		paths[7] = "assets/frogger/ph_spawn_bg.png";

		for (size_t i = 0; i < 8; i++)
		{
			m_texture_manager.load_texture(paths[i]);
		}
	}
}
