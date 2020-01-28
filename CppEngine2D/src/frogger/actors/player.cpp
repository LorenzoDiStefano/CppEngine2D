#include <frogger/actors/player.h>
#include <utility/types.h>
#include <engine/input.h>
#include <math.h>

using namespace frogger;

player::player(engine::draw_manager& draw_manager, engine::gfx::image_info* img_info)
{
	m_last_frame_input = 0;
	spawn_point.set((WINDOW_WIDTH - TILE_SIZE) / 2, (WINDOW_HEIGHT - TILE_SIZE));

	m_is_active = true;

	m_last_frame_input = 0;

	m_input_direction = my_math::vector2::zero();

	m_sprite.init(img_info, &draw_manager.renderer);

	rigid_body.set_bounding_box_size(m_sprite.sprite_rect.w, m_sprite.sprite_rect.h);
	rigid_body.is_active = true;
	rigid_body.owner = this;
	rigid_body.collider_type = engine::physics::rigid_body::COLLIDER_TYPE::PLAYER;

	rigid_body.add_to_collider_mask(engine::physics::rigid_body::COLLIDER_TYPE::WATER);
	rigid_body.add_to_collider_mask(engine::physics::rigid_body::COLLIDER_TYPE::LOG);
	rigid_body.add_to_collider_mask(engine::physics::rigid_body::COLLIDER_TYPE::END);
	rigid_body.add_to_collider_mask(engine::physics::rigid_body::COLLIDER_TYPE::CAR);

	respawn();
	draw_manager.add_sprite(*this, engine::draw_manager::draw_layer::FOREGROUND);
}

void player::update(const float delta_time)
{
	read_input(delta_time);

	const engine::physics::bounding_box my_bounding_box = rigid_body.get_bounding_box();


	if (rigid_body.get_position().x >= WINDOW_WIDTH - my_bounding_box.width())
	{
		rigid_body.set_position_x(WINDOW_WIDTH - my_bounding_box.width());
	}
	else if (rigid_body.get_position().x <= 0)
	{
		rigid_body.set_position_x(0);
	}

	if (rigid_body.get_position().y < 0)
	{
		rigid_body.set_position_y(0);
	}
	else if (rigid_body.get_position().y > WINDOW_HEIGHT - my_bounding_box.height())
	{
		rigid_body.set_position_y(WINDOW_HEIGHT - my_bounding_box.height());
	}

	if (m_log == nullptr)
	{
		if(m_on_water)
			respawn();

		return;
	}

	if (rigid_body.get_direction() == my_math::vector2::zero())
	{
		my_math::vector2 log_direction;

		log_direction = m_log->rigid_body.get_direction();

		rigid_body.set_direction(log_direction.x, log_direction.y);
		rigid_body.speed = m_log->rigid_body.speed;

	}

	m_on_water = false;
	m_log = nullptr;
}

void player::respawn()
{
	m_on_water = false;
	printf("Player died\n");
	m_position.set(spawn_point.x, spawn_point.y);
	rigid_body.set_position(spawn_point);
}

void player::read_input(const float dt)
{
	const type::uint8* keystates = engine::input::get_keyboard_state();

	my_math::vector2 direction = my_math::vector2::zero();

	if (keystates[(unsigned int)engine::input::KEYBOARD::LEFT_ARROW])
		direction.x--;
	else if (keystates[(unsigned int)engine::input::KEYBOARD::RIGHT_ARROW])
		direction.x++;
	else if (keystates[(unsigned int)engine::input::KEYBOARD::UP_ARROW])
		direction.y--;
	else if (keystates[(unsigned int)engine::input::KEYBOARD::DOWN_ARROW])
		direction.y++;

	int frame_input;

	if (direction.x == 0 && direction.y == 0)
	{
		frame_input = 0;
	}
	else
	{
		frame_input = 1;
		m_input_direction = direction;
	}

	if (m_last_frame_input == 1 && frame_input == 0)
	{
		rigid_body.set_direction(m_input_direction.x, m_input_direction.y);
		rigid_body.speed.x = abs(m_input_direction.x) * TILE_SIZE/dt; //tile size / delta time ;
		rigid_body.speed.y = abs(m_input_direction.y) * TILE_SIZE / dt;
	}
	else
	{
		rigid_body.set_direction(0, 0);
	}

	m_last_frame_input = frame_input;
}

void player::set_position(float x, float y)
{
	rigid_body.set_position(x, y);
	m_position.set(x, y);
}

void player::draw() const
{
	m_sprite.sprite_rect.x = rigid_body.get_position().x;
	m_sprite.sprite_rect.y = rigid_body.get_position().y;
	m_sprite.draw();
}

void player::on_collision(engine::physics::collision_info* ci)
{
	switch (ci->collider_type)
	{
	case (int)engine::physics::rigid_body::COLLIDER_TYPE::CAR:
		respawn();
		break;
	case (int)engine::physics::rigid_body::COLLIDER_TYPE::END:
		printf("win\n");
		exit(1);
		break;
	case (int)engine::physics::rigid_body::COLLIDER_TYPE::WATER:
		m_on_water = true;
		break;
	case (int)engine::physics::rigid_body::COLLIDER_TYPE::LOG:
		m_log = (obstacle*)ci->collider;

		break;
	default:
		break;
	}
}