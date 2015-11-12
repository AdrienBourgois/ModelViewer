#ifndef __DEVICE_H_INCLUDE__
#define __DEVICE_H_INCLUDE__

#include <memory>
#include <GL/glew.h>
#include <SDL.h>
#include "maths/Matrix.h"
#include "Driver.h"
#include "Scene.h"
#include "Window.h"
namespace id
{
    class Device
    {
    public:
        Device(Device const&)=delete;
        Device(Device &&)=delete;
        ~Device();

        Device&  operator=(Device const&) = delete;
        Device&  operator=(Device&&) = delete;

        static std::unique_ptr<Device>    create();
               Driver*                    getDriver() {return driver.get();}
               Window*                    getWindow() {return window.get();}
               Scene*                     getScene() {return scene.get();}
               void                       initGlew();
               void                       setAttribute();

               bool                       shouldRun();
               void                       run();
               //void setInitUniform(auto);

        //     EventManager*  getEventManager() {returd this->event_manager;}

    private:

        Device();
        //std::unique_ptr<EventManager> event_manager;
        
        std::unique_ptr<Driver> driver;
        std::unique_ptr<Window> window;
        std::unique_ptr<Scene> scene;
    };
}

#endif
