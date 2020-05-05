#ifndef FROGGER_WOOD_LOG
#define FROGGER_WOOD_LOG

#include "obstacle.hpp"
#include "../../engine/physics/rigid_body.hpp"

namespace engine
{
	struct game_object;
	class draw_manager;
	namespace gfx
	{
		struct image_info;
	}
}

namespace frogger
{
	struct wood_log : public frogger::obstacle
	{
		wood_log() = default;
		wood_log(engine::draw_manager& fm, engine::gfx::image_info* img_info);
		~wood_log() = default;

		void atach_player(engine::game_object*);
		void detach_player(engine::game_object*);

	private:
		engine::game_object* player;
	};
}

#endif