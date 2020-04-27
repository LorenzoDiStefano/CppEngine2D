#ifndef ENGINE_IMAGE_INFO
#define ENGINE_IMAGE_INFO

#include <string>

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

            //pointer to allocated image on the dynamic memory
            unsigned char* image;
            texture* texture;

            void load_texture(my_renderer* renderer);
            int load_image(const std::string& path);
        };
    }
}

#endif