#ifndef ENGINE_RIGID_BODY
#define ENGINE_RIGID_BODY

#include "bounding_box.hpp"
#include "../../utilities/types.hpp"

namespace engine
{
	struct game_object;

	namespace physics
	{
		class rigid_body
		{
		public:

			enum class COLLIDER_TYPE : type::uint32
			{
				NO_TYPE		= 0,
				PLAYER 		= 1,
				CAR			= 2,
				OBASTACLE	= 4,
				END			= 8,
				WATER		= 16,
				LOG			= 32
			};

			//member functions
			void update(const double delta_time);
			void on_collision(physics::collision_info* collision);
			bool collides(rigid_body& rb, collision_info& ci);
			void add_to_collider_mask(COLLIDER_TYPE t);
			void clear_collision_mask();
			bool check_collision_mask(rigid_body& rb);

			//setters
			void set_position(const float x, const float y);
			void set_position(const my_math::vector2& v2);
			void set_position_x(const float f);
			void set_position_y(const float f);

			void set_direction(const float x, const float y);
			void set_direction_x(const float f);
			void set_direction_y(const float f);

			void set_bounding_box_size(const float w, const float h);
			void set_bounding_box_size_w(const float f);
			void set_bounding_box_size_h(const float f);

			void set_collider_mask(const unsigned int t);

			//getters
			my_math::vector2 get_direction() const;
			my_math::vector2 get_position() const;
			const bounding_box& get_bounding_box() const;

			//ctor
			rigid_body();
			~rigid_body() = default;

			bool is_active;
			bool is_collision_affected;
			game_object* owner;
			COLLIDER_TYPE collider_type;
			my_math::vector2 speed;

		private:

			unsigned int m_collider_mask;
			my_math::vector2 m_position;
			my_math::vector2 m_direction;
			physics::bounding_box m_bounding_box;
		};
	}
}

#endif