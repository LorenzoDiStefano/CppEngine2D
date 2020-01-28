#pragma once
#include <engine/gfx/image_info.h>
#include <engine/gfx/texture.h>
#include <utility/types.h>

namespace engine
{
    namespace gfx
    {
        struct my_renderer;

        struct sprite
        {
            type::rect sprite_rect;

            void init(image_info* img_info, my_renderer* renderer);
            void draw();

            //private_members
            texture* texture;
            my_renderer* renderer;
        };
    }
}