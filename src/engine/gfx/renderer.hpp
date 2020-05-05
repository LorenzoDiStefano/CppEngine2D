#ifndef ENGINE_RENDERER
#define ENGINE_RENDERER

#include "../../utilities/types.hpp"
#include <cstdint>

namespace engine
{
	namespace gfx
	{
		struct sprite;
		struct texture;

		struct my_renderer
		{
			SDL_Renderer* renderer;
		private:
			SDL_Window* window;

			type::uint8 r, g, b, a;

		public:
			void init(const int w, const int h);
			void clear();
			void present();
			void set_color(type::uint8 r, type::uint8 g, type::uint8 b, type::uint8 a);
			void copy(texture* tex, SDL_Rect* surface);
			void quit();
		};
	}
}

#endif