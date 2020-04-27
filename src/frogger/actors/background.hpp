#ifndef FROGGER_BACKGROUND
#define FROGGER_BACKGROUND

#include "../src/engine/draw_manager.hpp"
#include "../src/engine/physics/rigid_body.hpp"

namespace frogger
{
	struct background : public engine::game_object
	{
		background() = delete;
		background(engine::draw_manager& fm, engine::gfx::image_info* img_info);
		~background() = default;

		mutable engine::gfx::sprite sprite;

		void update(const float dt) override;
		void draw() const override;
	};
}

#endif