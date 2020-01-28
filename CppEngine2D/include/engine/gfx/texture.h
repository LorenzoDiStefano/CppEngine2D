#pragma once
#include <cstdint>
#include <utility/types.h>
#include <engine/gfx/renderer.h>

namespace engine
{
	namespace gfx
	{
		struct texture
		{
			SDL_Texture* my_texture;

			void create(my_renderer* renderer, int width, int height);
			void enable_blend_mode();
			void unlock();
			void lock(void** p, int* i);
		};
	}
}