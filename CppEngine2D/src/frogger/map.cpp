#include <frogger/map.h>
#include <frogger/actors/bg_water.h>

using namespace frogger;

#define TEXTURE_FROG        0
#define TEXTURE_ROAD        1
#define TEXTURE_WATER       2
#define TEXTURE_WIN         3
#define TEXTURE_CAR         4
#define TEXTURE_CAR_FLIP    5
#define TEXTURE_LOG         6
#define TEXTURE_SPAWN       7
#define TEXTURE_MAX         8

map::map() {}

void map::init(engine::draw_manager& dm, engine::texture_manager* tm, engine::physics_manager& pm, engine::update_manager& um)
{
	for (size_t i = 0; i < 11; i++)
	{
		int lane_direction;
		if (i == 0)
		{
			bg_water* bg = new bg_water(dm, &tm->textures[TEXTURE_WIN]);
			bg->rigid_body.collider_type = engine::physics::rigid_body::COLLIDER_TYPE::END;
			bg->rigid_body.set_bounding_box_size_h(75);//"cheating" a bit
			pm.add_rigid_body(&bg->rigid_body);

			um.add_game_object(*bg);

			backgrounds[i] = bg;
		}
		else if (i == 10)
		{
			backgrounds[i] = new background(dm, &tm->textures[TEXTURE_SPAWN]);
		}
		else
		{
			int random_bg = (rand() % 2);
			lane_direction = (rand() % 2) * 2 - 1;
			float random_additive_velocity = ((float)rand() / (float)(RAND_MAX)) * base_x_velocity;
			float lane_velocity = (random_additive_velocity + base_x_velocity) * lane_direction;

			if (random_bg)
			{

				bg_water* bg = new bg_water(dm, &tm->textures[TEXTURE_WATER]);
				bg->rigid_body.collider_type = engine::physics::rigid_body::COLLIDER_TYPE::WATER;
				pm.add_rigid_body(&bg->rigid_body);
				um.add_game_object(*bg);
				backgrounds[i] = bg;

				obstacles[used_obstacles] = new obstacle(dm, &tm->textures[TEXTURE_LOG]);

				obstacles[used_obstacles]->rigid_body.set_position((rand() % 3) * TILE_SIZE, TILE_SIZE * i);
				obstacles[used_obstacles]->rigid_body.speed.set(lane_velocity, 0);
				obstacles[used_obstacles]->rigid_body.collider_type = engine::physics::rigid_body::COLLIDER_TYPE::LOG;
				obstacles[used_obstacles]->rigid_body.set_direction(1, 0);

				pm.add_rigid_body(&obstacles[used_obstacles]->rigid_body);
				um.add_game_object(*obstacles[used_obstacles]);
				used_obstacles++;

				if ((rand() % 2))
				{
					obstacles[used_obstacles] = new obstacle(dm, &tm->textures[TEXTURE_LOG]);
					obstacles[used_obstacles]->rigid_body.set_position(((rand() % 5) + 5) * TILE_SIZE, TILE_SIZE * i);
					obstacles[used_obstacles]->rigid_body.speed.set(lane_velocity, 0);
					obstacles[used_obstacles]->rigid_body.collider_type = engine::physics::rigid_body::COLLIDER_TYPE::LOG;
					obstacles[used_obstacles]->rigid_body.set_direction(1, 0);
					pm.add_rigid_body(&obstacles[used_obstacles]->rigid_body);
					um.add_game_object(*obstacles[used_obstacles]);
					used_obstacles++;
				}
			}
			else
			{
				backgrounds[i] = new background(dm, &tm->textures[TEXTURE_ROAD]);


				if (lane_direction > 0)
					obstacles[used_obstacles] = new obstacle(dm, &tm->textures[TEXTURE_CAR_FLIP]);
				else
					obstacles[used_obstacles] = new obstacle(dm, &tm->textures[TEXTURE_CAR]);

				obstacles[used_obstacles]->rigid_body.set_position((rand() % 3) * TILE_SIZE, TILE_SIZE * i);
				obstacles[used_obstacles]->rigid_body.speed.set(lane_velocity, 0);
				obstacles[used_obstacles]->rigid_body.set_direction(1, 0);
				obstacles[used_obstacles]->rigid_body.collider_type = engine::physics::rigid_body::COLLIDER_TYPE::CAR;

				pm.add_rigid_body(&obstacles[used_obstacles]->rigid_body);
				um.add_game_object(*obstacles[used_obstacles]);
				used_obstacles++;
				if (rand() % 2)
				{
					if (lane_direction > 0)
						obstacles[used_obstacles] = new obstacle(dm, &tm->textures[TEXTURE_CAR_FLIP]);
					else
						obstacles[used_obstacles] = new obstacle(dm, &tm->textures[TEXTURE_CAR]);

					obstacles[used_obstacles]->rigid_body.set_position(((rand() % 5) + 5) * TILE_SIZE, TILE_SIZE * i);
					obstacles[used_obstacles]->rigid_body.speed.set(lane_velocity, 0);
					obstacles[used_obstacles]->rigid_body.set_direction(1, 0);
					obstacles[used_obstacles]->rigid_body.collider_type = engine::physics::rigid_body::COLLIDER_TYPE::CAR;

					pm.add_rigid_body(&obstacles[used_obstacles]->rigid_body);
					um.add_game_object(*obstacles[used_obstacles]);
					used_obstacles++;
				}
			}

		}
		backgrounds[i]->set_position(0, TILE_SIZE * i);
	}
}