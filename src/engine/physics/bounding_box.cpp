#include "../src/engine/physics/bounding_box.hpp"

namespace engine
{
	namespace physics
	{
		//getters
		float bounding_box::height() const
		{
			return m_height;
		}

		float bounding_box::width() const
		{
			return m_width;
		}

		float bounding_box::half_height() const
		{
			return m_half_height;
		}

		float bounding_box::half_width() const
		{
			return m_half_width;
		}

		//setters
		void bounding_box::set_width(const float width)
		{
			m_width = width;
			m_half_width = width * .5f;
		}

		void bounding_box::set_height(const float height)
		{
			m_height = height;
			m_half_height = height * .5f;
		}

		void bounding_box::set_size(const float width, const float height)
		{
			m_width = width;
			m_half_width = width * .5f;
			m_height = height;
			m_half_height = height * .5f;
		}

		//methods
		int bounding_box::check_collision(const bounding_box& other, collision_info& collision_info)
		{
			if (position.x < other.position.x + other.m_width &&
				position.x + m_width > other.position.x&&

				position.y < other.position.y + other.m_height &&
				position.y + m_height > other.position.y)
			{
				float x = 0;
				float y = 0;

				if (position.x < other.position.x)
					x = (position.x + m_width) - other.position.x;
				else
					x = ((position.x) - (other.position.x + other.m_width));

				if (position.y < other.position.y)
					y = (position.y + m_height) - other.position.y;
				else
					y = ((position.y) - (other.position.y + other.m_height));

				collision_info.delta.set(x, y);
				return 1;
			}

			return -1;
		}
	}
}
