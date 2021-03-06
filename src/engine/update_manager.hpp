#ifndef ENGINE_UPDATE_MANAGER
#define ENGINE_UPDATE_MANAGER

#include <vector>

namespace engine
{
	struct game_object;

	class update_manager
	{
	public:

		void add_game_object(game_object& go);
	    void update(const double delta_time);

	private:

		std::vector<game_object*> m_game_objects;
	};
}

#endif