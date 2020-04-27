#ifndef ENGINE_EVENT
#define ENGINE_EVENT

#include "../src/utilities/types.hpp"

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

#endif