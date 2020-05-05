#ifndef FROGGER_MAP
#define FROGGER_MAP

namespace engine
{
	class draw_manager;
	class texture_manager;
	class physics_manager;
	class update_manager;
}

namespace frogger
{
	struct obstacle;
	struct background;
	
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