#ifndef ENGINE_INPUT
#define ENGINE_INPUT

#include <cstdint>
#include <utility/types.h>

namespace engine
{
	struct input
	{
		static const type::uint8* get_keyboard_state();

		enum class KEYBOARD : type::uint32
		{
			LEFT_ARROW = SDL_SCANCODE_LEFT,
			RIGHT_ARROW = SDL_SCANCODE_RIGHT,
			UP_ARROW = SDL_SCANCODE_UP,
			DOWN_ARROW = SDL_SCANCODE_DOWN
		};
	};
}

#endif