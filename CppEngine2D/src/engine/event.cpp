#pragma once

#include <engine/event.h>

using namespace engine;


const int event::poll_event()
{
    return SDL_PollEvent(&this->my_event);
}

unsigned int event::get_type()
{
    return this->my_event.type;
}
