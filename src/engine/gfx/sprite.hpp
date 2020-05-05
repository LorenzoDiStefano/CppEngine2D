#ifndef ENGINE_SPRITE
#define ENGINE_SPRITE

#include "../../utilities/types.hpp"

namespace engine
{
    namespace gfx
    {
        struct my_renderer;
        struct texture;
        struct image_info;

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

#endif