#ifndef FROGGER_MAP
#define FROGGER_MAP

#include <frogger/actors/background.hpp>
#include <frogger/actors/obstacle.hpp>
#include <engine/draw_manager.hpp>
#include <engine/physics_manager.hpp>
#include <engine/texture_mananger.hpp>
#include <engine/update_manager.hpp>

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

#endif // !FROGGER_MAP