#ifndef __DEVICE_H_INCLUDE__
#define __DEVICE_H_INCLUDE__

#include <memory>
#include <SDL.h>
#include <vector>
#include "maths/Matrix.h"
#include "Driver.h"

namespace id
{
    class Window
    {
        
    };

    class Device
    {
    public:
        ~Device();
        Device();

        Device(Device const&) = delete;
        Device(Device&&) = delete;
        Device&  operator=(Device const&) = delete;
        Device&  operator=(Device&&) = delete;

        void create();

        bool shouldRun();
        void run();
        void setInitUniform(auto);

        SDL_Event getEvent() {return this->event;}

    private:
        SDL_Event event;

        Driver driver;

        GLuint prg_id;
        
        //std::unique_ptr<Window>          Window;
        //std::unique_ptr<VideoDriver>     VideoDriver;
    };
}

#endif
