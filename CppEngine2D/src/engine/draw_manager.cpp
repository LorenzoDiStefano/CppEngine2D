#include "engine/draw_manager.hpp"

namespace engine
{
	void draw_manager::draw_scene()
	{
		renderer.set_color(0, 0, 0, 255);
		renderer.clear();

		for (int i = 0; i < (int)draw_layer::MAX; i++)
		{
			std::vector<const game_object*> layer = sprites[i];

			for (const game_object* sprite : layer)
			{
				sprite->draw();
			}
		}
		renderer.present();
	}

	void draw_manager::add_sprite(const game_object& sprite, const draw_layer layer)
	{
		sprites[(int)layer].push_back(&sprite);
	}

	draw_manager::draw_manager()
	{
		renderer.init((int)WINDOW_WIDTH, (int)WINDOW_HEIGHT);
	}

	void draw_manager::quit()
	{
		renderer.quit();
	}
}
