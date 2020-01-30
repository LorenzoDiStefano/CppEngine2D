#include <engine/game_object.h>

namespace engine
{
	void game_object::on_collision(engine::physics::collision_info* ci) { return; }

	float game_object::x() const { return m_position.x; }

	float game_object::y() const { return m_position.y; }

	void game_object::set_position(float x, float y) { m_position.set(x, y); }

	void game_object::activate() { m_is_active = true; };

	void game_object::deactivate() { m_is_active = false; }

	bool game_object::is_active() const { return m_is_active; }

	void game_object::set_position(my_math::vector2 position) { m_position = position; }

}