#ifndef ENGINE_TYPES
#define ENGINE_TYPES

#ifndef SDL_MAIN_HANDLED
#define SDL_MAIN_HANDLED
#include <SDL.h>
#endif

namespace type
{
	using uint8 = Uint8;
	using uint16 = Uint16;
	using uint32 = Uint32;
	using rect = SDL_Rect;
}

#endif