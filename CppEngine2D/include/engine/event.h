#pragma once

#include <utility/types.h>

namespace engine
{
	struct event
	{
		const int poll_event();
		unsigned int get_type();

		SDL_Event my_event;

		enum class TYPE : unsigned int
		{
			QUIT = SDL_QUIT
		};
	};
}