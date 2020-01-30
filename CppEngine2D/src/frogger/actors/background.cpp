#include <frogger/actors/background.h>

namespace frogger
{
	background::background(engine::draw_manager& draw_manager, engine::gfx::image_info* img_info)
	{
		m_is_active = true;

		sprite.init(img_info, &draw_manager.renderer);

		//stretch ph art
		sprite.sprite_rect.w = WINDOW_WIDTH;
		sprite.sprite_rect.h = TILE_SIZE;

		draw_manager.add_sprite(*this, engine::draw_manager::draw_layer::BACKGROUND);
	}

	void background::update(const float delta_time)
	{
		//todo
		return;
	}

	void background::draw() const
	{
		sprite.sprite_rect.x = m_position.x;
		sprite.sprite_rect.y = m_position.y;

		sprite.draw();
	}
}