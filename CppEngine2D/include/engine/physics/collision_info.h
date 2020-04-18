#ifndef ENGINE_COLLISION_INFO
#define ENGINE_COLLISION_INFO

#include <math/vector2.h>

namespace engine
{
	//forward declaration
	struct game_object;

	namespace physics
	{
		//POD
		struct collision_info
		{
			engine::game_object* collider;
			my_math::vector2 delta;
			unsigned int collider_type;
		};
	}
}

#endif