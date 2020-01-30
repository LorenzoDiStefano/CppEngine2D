#include <engine/gfx/image_info.h>
#include <engine/gfx/renderer.h>
#include <engine/gfx/texture.h>
#include <utility/types.h>

#ifndef STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION
#include "../../stb_image.h"
#endif

namespace engine
{
	namespace gfx
	{
		int image_info::load_image(const char* path)
		{
			image = stbi_load(path, &width, &height, &comp, STBI_rgb_alpha);

			SDL_Log("Loading img: %s", path);
			if (!image)
			{
				SDL_Log("Error loading img: %s", path);
				return 1;
			}

			length = width * height;

			return 0;
		}

		void image_info::load_texture(gfx::my_renderer* renderer)
		{
			if (this->image == nullptr)
			{
				printf("load_texture error, no image loaded before creating texture.");
				exit(1);
			}

			texture = new engine::gfx::texture();

			texture->create(renderer, width, height);

			if (!texture)
				printf("error");

			texture->enable_blend_mode();

			type::uint8* pixels = NULL;
			int pitch = 0;

			texture->lock((void**)&pixels, &pitch);

			memcpy(pixels, (void*)image, (size_t)height * 4 * width);

			texture->unlock();

			return;
		}
	}
}
