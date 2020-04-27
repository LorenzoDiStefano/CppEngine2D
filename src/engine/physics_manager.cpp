#include "../src/engine/game_object.hpp"
#include "../src/engine/physics/collision_info.hpp"
#include "../src/engine/physics_manager.hpp"

namespace engine
{
	void physics_manager::add_rigid_body(physics::rigid_body* rb)
	{
		rigid_bodies.push_back(rb);
	}

	void physics_manager::update(const double delta_time)
	{
		for (physics::rigid_body* rb : rigid_bodies)
		{
			rb->update(delta_time);
		}
	}

	void physics_manager::check_collisions()
	{
		for (int i = 0; i < rigid_bodies.size() - 1; i++)
		{
			if (rigid_bodies[i]->is_collision_affected && rigid_bodies[i]->is_active)
			{
				for (int j = i + 1; j < rigid_bodies.size(); j++)
				{
					if (rigid_bodies[j]->is_collision_affected && rigid_bodies[j]->is_active)
					{
						bool check_first = rigid_bodies[i]->check_collision_mask(*rigid_bodies[j]);
						bool check_second = rigid_bodies[j]->check_collision_mask(*rigid_bodies[i]);

						if (!(check_first || check_second))
							continue;

						physics::collision_info ci;

						if (rigid_bodies[i]->collides(*rigid_bodies[j], ci))
						{
							if (check_first)
							{
								ci.collider = rigid_bodies[j]->owner;
								ci.collider_type = (unsigned int)rigid_bodies[j]->collider_type;
								rigid_bodies[i]->owner->on_collision(&ci);
							}
							if (check_second)
							{
								ci.collider = rigid_bodies[i]->owner;
								ci.collider_type = (unsigned int)rigid_bodies[i]->collider_type;
								rigid_bodies[j]->owner->on_collision(&ci);
							}
						}
					}
				}
			}
		}
	}
}
