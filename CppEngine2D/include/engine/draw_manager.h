#ifndef ENGINE_DRAW_MANAGER
#define ENGINE_DRAW_MANAGER

#include <engine/gfx/sprite.h>
#include <engine/game_object.h>
#include <engine/gfx/renderer.h>
#include <vector>

namespace engine
{
    class draw_manager
    {
    public:
        #define WINDOW_WIDTH 858
        #define WINDOW_HEIGHT 858
        #define TILE_SIZE 78

        enum class draw_layer : const int
        {
            BACKGROUND = 0,
            FOREGROUND = 1,
            UI         = 2,
            MAX        = 3
        };
        
        void add_sprite(const game_object& sprite, const draw_layer layer);
        void draw_scene();
        void quit();

        draw_manager();
        ~draw_manager() = default;

        gfx::my_renderer renderer;

    private:
        std::vector<const game_object*> sprites[(int)draw_layer::MAX];
    };
}

#endif