#ifndef ENGINE_TEXTURE
#define ENGINE_TEXTURE

#include <cstdint>
#include <utility/types.h>
#include <engine/gfx/renderer.h>

namespace engine
{
	namespace gfx
	{
		struct texture
		{
		//private:
			SDL_Texture* my_texture;
		public:
			void create(my_renderer* renderer, int width, int height);
			void enable_blend_mode();
			void unlock();
			void lock(void** p, int* i);
		};
	}
}

#endif