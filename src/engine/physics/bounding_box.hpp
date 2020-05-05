#ifndef ENGINE_BOUNDING_BOX
#define ENGINE_BOUNDING_BOX

#include "../../math/vector2.hpp"

namespace engine
{
	namespace physics
	{
		struct collision_info;

		class bounding_box
		{
		public:

			//getters
			float height() const;
			float width() const;

			float half_height() const;
			float half_width() const;

			//setters
			void set_width(const float width);
			void set_height(const float height);
			void set_size(const float width, const float height);

			//member functions
			int check_collision(const bounding_box& other, collision_info& collision_info);

			//public member vars
			my_math::vector2 position;

		private:

			//private member vars
			float m_half_width;
			float m_half_height;
			float m_width;
			float m_height;
		};
	}
}

#endif