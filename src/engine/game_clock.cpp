#include "game_clock.hpp"
#include "../utilities/types.hpp"

namespace engine
{
	game_clock::game_clock()
	{
		m_elapsed_time = SDL_GetPerformanceCounter();
		m_performance_frequency = 1.0f / (double)SDL_GetPerformanceFrequency();//to return in ms divide by 0.001f;
	}

	float game_clock::get_now()
	{
		m_last_frame_elapsed_time = m_elapsed_time;
		m_elapsed_time = SDL_GetPerformanceCounter();

		//return delta time in seconds
		return ((m_elapsed_time - m_last_frame_elapsed_time) * m_performance_frequency);
	}
}