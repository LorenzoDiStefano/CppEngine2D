#include <engine/gfx/renderer.h>

using namespace engine::gfx;

void my_renderer::clear()
{
    SDL_RenderClear(renderer);
}

void my_renderer::present()
{
    SDL_RenderPresent(renderer);
}

void my_renderer::set_color(type::uint8 r, type::uint8 g, type::uint8 b, type::uint8 a)
{
    SDL_SetRenderDrawColor(renderer, r, g, b, a);
}

void my_renderer::copy(texture* tex, SDL_Rect* surface)
{
    SDL_RenderCopy(renderer, tex->my_texture, NULL, surface);
}

void my_renderer::init(const int w, const int h)
{
    window = SDL_CreateWindow("Game", 100, 100, w, h, SDL_WINDOW_SHOWN);

    if (!window)
    {
        return;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);

    if (!renderer)
    {
        return;
    }

    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
}

void my_renderer::quit()
{
    SDL_Quit();
}