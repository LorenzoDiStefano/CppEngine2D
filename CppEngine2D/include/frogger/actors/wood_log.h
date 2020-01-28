#pragma once
#include <engine/draw_manager.h>
#include <engine/physics/rigid_body.h>
#include <frogger/actors/obstacle.h>

namespace engine
{
	struct game_object;
}

namespace frogger
{
	struct wood_log : public frogger::obstacle
	{
		wood_log();
		wood_log(engine::draw_manager& fm, engine::gfx::image_info* img_info);
		~wood_log() = default;

		void atach_player(game_object*);
		void detach_player(game_object*);
		

	private:
		game_object* player;
	};
}