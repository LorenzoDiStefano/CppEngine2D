#include <engine/input.h>

using namespace engine;

const type::uint8* input::get_keyboard_state()
{
	return SDL_GetKeyboardState(NULL);
}
