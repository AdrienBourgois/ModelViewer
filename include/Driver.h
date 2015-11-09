#ifndef __DRIVER_INCLUDE__
#define __DRIVER_INCLUDE__

#include <SDL.h>
#include <GL/glew.h>
#include <Scene.h>

namespace id
{
struct Driver
{
public:
    Driver() = default;
    Driver(SDL_Window*);
    ~Driver();

    void create();

    SDL_GLContext getContext() {return this->context;}
    SDL_Window* getWindow() {return this->window;}

    void setContext(SDL_GLContext ctx) {this->context = ctx;}
    void setWindow(SDL_Window* window) {this->window = window;}

    void draw();

private:
    SDL_GLContext context;
    SDL_Window* window;
    Scene scene;


};

}

#endif
