#pragma once
#include <frogger/actors/background.h>
#include <frogger/actors/obstacle.h>
#include <engine/draw_manager.h>
#include <engine/physics_manager.h>
#include <engine/texture_mananger.h>
#include <engine/update_manager.h>

namespace frogger
{
	struct map
	{
		background* backgrounds[11];
		obstacle* obstacles[20];

		int used_obstacles = 0;
		int base_x_velocity = 100;

		map();
		void init(engine::draw_manager& dm, engine::texture_manager* img_info,engine::physics_manager& pm,engine::update_manager& um);
	};
}