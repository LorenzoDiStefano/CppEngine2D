#include <engine/gfx/texture.h>


using namespace engine::gfx;

void texture::create(my_renderer* renderer, int width, int height)
{
    my_texture = SDL_CreateTexture(renderer->renderer, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_STREAMING, width, height);

}

void texture::enable_blend_mode()
{
    SDL_SetTextureBlendMode(my_texture, SDL_BLENDMODE_BLEND);
}

void texture::lock(void** p, int* i)
{
    SDL_LockTexture(my_texture, NULL, p, i);
}

void texture::unlock()
{
    SDL_UnlockTexture(my_texture);
}