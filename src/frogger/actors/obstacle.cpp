#include "obstacle.hpp"
#include "../../engine/draw_manager.hpp"

namespace frogger
{
	obstacle::obstacle(engine::draw_manager& dm, engine::gfx::image_info* img_info)
	{
		m_is_active = 1;

		sprite.init(img_info, &dm.renderer);

		rigid_body.set_bounding_box_size(sprite.sprite_rect.w, sprite.sprite_rect.h);
		rigid_body.is_active = true;
		rigid_body.owner = this;

		dm.add_sprite(*this, engine::draw_manager::draw_layer::FOREGROUND);
	}

	void obstacle::update(const float dt)
	{
		const engine::physics::bounding_box my_bounding_box = rigid_body.get_bounding_box();

		if (rigid_body.get_position().x > WINDOW_WIDTH)
		{
			rigid_body.set_position_x(-my_bounding_box.width());
		}
		else if (rigid_body.get_position().x < -(my_bounding_box.width()))
		{
			rigid_body.set_position_x(WINDOW_WIDTH);
		}
	}

	void obstacle::draw() const
	{
		sprite.sprite_rect.x = m_position.x;
		sprite.sprite_rect.y = m_position.y;
		sprite.draw();
	}
}
