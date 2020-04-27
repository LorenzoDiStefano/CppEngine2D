#ifndef ENGINE_SPRITE
#define ENGINE_SPRITE

#include "../src/engine/gfx/image_info.hpp"
#include "../src/engine/gfx/texture.hpp"
#include "../src/utilities/types.hpp"

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

#endif