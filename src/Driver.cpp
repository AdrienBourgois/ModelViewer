#include "Driver.h"
#include <iostream>

namespace id
{
    void Driver::create()
    {
        this->window = SDL_CreateWindow("Opengl 4.2", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 400, 400, SDL_WINDOW_OPENGL);
        SDL_assert(this->window);

        context = SDL_GL_CreateContext(window);
        SDL_assert(this->context);

        glewExperimental = GL_TRUE;
        auto status = glewInit();
        if (status != GLEW_OK)
            fprintf(stderr, "Error: %s\n", glewGetErrorString(status));
        SDL_assert(status == GLEW_OK);

        scene.create();
    }

    Driver::~Driver()
    {
        SDL_GL_DeleteContext(getContext());
        SDL_DestroyWindow(window);
    }

    Driver::Driver(SDL_Window* window)
    {
        this->window = window;
    }

    void Driver::draw()
    {
        scene.draw();
    }
}
