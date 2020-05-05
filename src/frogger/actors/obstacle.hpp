#ifndef FROGGER_OBSTACLE
#define FROGGER_OBSTACLE

#include "../../engine/physics/rigid_body.hpp"
#include "../../engine/gfx/sprite.hpp"
#include "../../engine/game_object.hpp"

namespace engine
{
	class draw_manager;
}

namespace frogger
{
	struct obstacle : public engine::game_object
	{
		obstacle() = delete;
		obstacle(engine::draw_manager& fm, engine::gfx::image_info* img_info);
		~obstacle() = default;

		mutable engine::gfx::sprite sprite;
		engine::physics::rigid_body rigid_body;

		void update(const float dt) override;
		void draw() const override;
	};
}

#endif