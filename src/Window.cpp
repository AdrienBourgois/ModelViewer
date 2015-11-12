#include "Window.h"


namespace id{

    Window::Window()
    {
        SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION,"Creating Window...");
        this->window = SDL_CreateWindow("Model View", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1600,1200, SDL_WINDOW_OPENGL);
        SDL_assert(this->window);
    }

    Window::~Window()
    {
        SDL_DestroyWindow(this->window);
    }

    std::unique_ptr<Window> Window::create()
    {
        Window * window = new (std::nothrow) Window;
        return std::unique_ptr<Window>(window);
    }





}//id
