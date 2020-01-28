#include "engine/update_manager.h"

using namespace engine;

update_manager::update_manager()
{
    this->m_game_objects;
}


void update_manager::add_game_object(game_object& go)
{
    m_game_objects.push_back(&go);
}

void update_manager::update(const double delta_time)
{
    for (engine::game_object* sprite : m_game_objects)
    {
        sprite->update(delta_time);
    }
}
