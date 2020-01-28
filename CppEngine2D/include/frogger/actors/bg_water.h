#pragma once
#include <frogger/actors/background.h>

namespace frogger
{
	struct bg_water : public frogger::background
	{
		bg_water() = delete;
		bg_water(engine::draw_manager& fm, engine::gfx::image_info* img_info);
		~bg_water() = default;

		void set_position(float x, float y) override;

		engine::physics::rigid_body rigid_body;

	};
}