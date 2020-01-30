#pragma once
#include "utility/types.h"

namespace engine
{
	class game_clock
	{
	public:
		//member functions
		float get_now();
		
		//ctor
		game_clock();

	private:

		//private member vars
		type::uint32 m_elapsed_time;
		type::uint32 m_last_frame_elapsed_time;
		double m_performance_frequency;

	};
}