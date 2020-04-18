#ifndef ENGINE_IMAGE_INFO
#define ENGINE_IMAGE_INFO

#include <utility/types.h>

namespace engine
{
    namespace gfx
    {
        //POD
        struct my_renderer;
        struct texture;

        struct image_info
        {
            int width;
            int height;
            int comp;
            int length;
            unsigned char* image;
            texture* texture;

            void load_texture(my_renderer* renderer);
            int load_image(const char* path);
        };
    }
}

#endif