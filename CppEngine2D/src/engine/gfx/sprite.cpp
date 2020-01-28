#include <engine/gfx/sprite.h>
#include <engine/gfx/renderer.h>

void engine::gfx::sprite::init(image_info* img_info, engine::gfx::my_renderer* renderer)
{
    texture = img_info->texture;
    sprite_rect.w = img_info->width;
    sprite_rect.h = img_info->height;
    sprite_rect.x = 0;
    sprite_rect.y = 0;
    this->renderer = renderer;
}

void engine::gfx::sprite::draw()
{
    renderer->copy(texture, &sprite_rect);
}