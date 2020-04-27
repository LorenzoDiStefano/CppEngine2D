#include <frogger/actors/bg_water.hpp>

namespace frogger
{
	bg_water::bg_water(engine::draw_manager& fm, engine::gfx::image_info* img_info)
		: background(fm, img_info)
	{

		rigid_body.set_bounding_box_size(sprite.sprite_rect.w, sprite.sprite_rect.h);
		rigid_body.is_active = true;
		rigid_body.owner = this;
	}


	void bg_water::set_position(float x, float y)
	{
		rigid_body.set_position(x, y);
		m_position.set(x, y);
	}
}