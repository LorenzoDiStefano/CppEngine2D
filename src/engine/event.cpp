#include "event.hpp"

namespace engine
{
	const int event::poll_event()
	{
		return SDL_PollEvent(&this->my_event);
	}

	unsigned int event::get_type()
	{
		return this->my_event.type;
	}
}