#ifndef _WINDOW_H
#define _WINDOW_H

#include <new>
#include <memory>
#include <GL/glew.h>
#include <SDL.h>
#include <string>



namespace id
{
    class Window
    {
        public: 
            Window(Window const&)=delete;
            Window(Window &&)=delete;
            ~Window();

            static std::unique_ptr<Window> create();
                   SDL_Window*             getWindow() {return window;}

        private:
                   Window();
                   SDL_Window* window;
    };
}//id

#endif
