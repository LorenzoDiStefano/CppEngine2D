#include "wood_log.hpp"

using namespace frogger;

wood_log::wood_log(engine::draw_manager& fm, engine::gfx::image_info* img_info)
	: obstacle(fm, img_info)
{
}
