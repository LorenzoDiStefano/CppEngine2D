#ifndef FROGGER_BACKGROUND
#define FROGGER_BACKGROUND

#include "../../engine/gfx/sprite.hpp"
#include "../../engine/game_object.hpp"

namespace engine
{
	class draw_manager;

	namespace gfx
	{
		struct image_info;
	}
}

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