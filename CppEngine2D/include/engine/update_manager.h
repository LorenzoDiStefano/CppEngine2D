#pragma once
#include <engine/game_object.h>
#include <vector>

namespace engine
{
	class update_manager
	{
	public:

		void add_game_object(game_object& go);
	    void update(const double delta_time);

	private:

		std::vector<game_object*> m_game_objects;
	};
}


