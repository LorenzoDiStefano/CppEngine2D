#pragma once
#include <engine/physics/rigid_body.h>
#include <vector>

namespace engine
{
	struct physics_manager
	{
		std::vector < physics::rigid_body* > rigid_bodies;

		void add_rigid_body(physics::rigid_body* rb);
		void update(const double delta_time);
		void check_collisions();
	};
}
