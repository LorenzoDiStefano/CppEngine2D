#ifndef FROGGER_MAP
#define FROGGER_MAP

#include "../src/frogger/actors/background.hpp"
#include "../src/frogger/actors/obstacle.hpp"
#include "../src/engine/draw_manager.hpp"
#include "../src/engine/physics_manager.hpp"
#include "../src/engine/texture_manager.hpp"
#include "../src/engine/update_manager.hpp"

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