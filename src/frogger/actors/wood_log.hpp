#pragma once
#include "../src/engine/draw_manager.hpp"
#include "../src/engine/physics/rigid_body.hpp"
#include "../src/frogger/actors/obstacle.hpp"

namespace engine
{
	struct game_object;
}

namespace frogger
{
	struct wood_log : public frogger::obstacle
	{
		wood_log() = default;
		wood_log(engine::draw_manager& fm, engine::gfx::image_info* img_info);
		~wood_log() = default;

		void atach_player(game_object*);
		void detach_player(game_object*);
		

	private:
		game_object* player;
	};
}