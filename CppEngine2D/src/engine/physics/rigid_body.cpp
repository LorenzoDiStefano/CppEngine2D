#include <engine/physics/collision_info.hpp>
#include <engine/physics/rigid_body.hpp>

namespace engine
{
	namespace physics
	{
		void rigid_body::set_direction(const float x, const float y)
		{
			m_direction.set(x, y);
			m_direction.normalize();
		}

		void rigid_body::set_direction_x(const float f)
		{
			m_direction.x = f;
			m_direction.normalize();
		}

		void rigid_body::set_direction_y(const float f)
		{
			m_direction.y = f;
			m_direction.normalize();
		}

		void rigid_body::update(const double delta_time)
		{
			if (is_active)
			{
				m_position += speed * m_direction * delta_time;

				m_bounding_box.position = m_position;

				owner->set_position(m_position.x, m_position.y);
				is_collision_affected = true;

			}
		}

		bool rigid_body::collides(rigid_body& rb, collision_info& ci)
		{
			if (m_bounding_box.check_collision(rb.m_bounding_box, ci) == -1)
				return false;

			ci.collider = rb.owner;
			return true;
		}

		void rigid_body::on_collision(physics::collision_info* collision)
		{
			//todo?
			return;
		}

		void rigid_body::set_bounding_box_size(const float w, const float h)
		{
			m_bounding_box.set_size(w, h);
		}

		void rigid_body::set_bounding_box_size_w(const float f)
		{
			m_bounding_box.set_width(f);
		}

		void rigid_body::set_bounding_box_size_h(const float f)
		{
			m_bounding_box.set_height(f);
		}

		const bounding_box& rigid_body::get_bounding_box() const
		{
			return m_bounding_box;
		}

		rigid_body::rigid_body()
		{
			collider_type = rigid_body::COLLIDER_TYPE::NO_TYPE;
			m_collider_mask = 0;
		}

		void rigid_body::add_to_collider_mask(COLLIDER_TYPE t)
		{
			m_collider_mask |= (int)t;
		}

		void rigid_body::set_collider_mask(const unsigned int t)
		{
			m_collider_mask = t;
		}

		void rigid_body::clear_collision_mask()
		{
			m_collider_mask = 0;
		}

		bool rigid_body::check_collision_mask(rigid_body& rb)
		{
			return (this->m_collider_mask & (unsigned int)rb.collider_type) != 0;
		}

		void rigid_body::set_position(const float x, const float y)
		{
			m_position.set(x, y);
			m_bounding_box.position.set(x, y);
		}

		void rigid_body::set_position(const my_math::vector2& v2)
		{
			m_position = v2;
			m_bounding_box.position = v2;
		}

		my_math::vector2 rigid_body::get_position() const
		{
			return m_position;
		}

		void rigid_body::set_position_x(const float f)
		{
			m_position.x = f;
			m_bounding_box.position.x = f;

		}

		void rigid_body::set_position_y(const float f)
		{
			m_position.y = f;
			m_bounding_box.position.y = f;
		}

		my_math::vector2 rigid_body::get_direction()const
		{
			return m_direction;
		}
	}
}