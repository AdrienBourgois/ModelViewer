#include "Driver.h"
#include <iostream>

#include "Device.h"
namespace id
{
    Driver::Driver(SDL_Window * window)
    {
        SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION,"creating contex...");
        this->context = createContext(window);
        this->shaders = std::map<std::string,Shader*>();
        SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION,"contxt created");
    }

    std::unique_ptr<Driver> Driver::create(Device & device)
    {
        SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION,"creating Driver...");
        Driver* drv = new (std::nothrow) Driver (device.getWindow()->getWindow());
        SDL_assert(drv);
        return std::unique_ptr<Driver>(drv);
    }

    Driver::~Driver()
    {
        SDL_GL_DeleteContext(getContext());
    }

    SDL_GLContext Driver::createContext(SDL_Window* window)
    {
        SDL_GLContext gl_context = SDL_GL_CreateContext(window);
        SDL_assert(gl_context);
        return gl_context;
    }

    void Driver::addShader(std::string const& name)
    {
        if(shaders.find(name)==shaders.end())
        {
            SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION,"creating new shader");
            shaders[name] = new Shader(name);
        }
        else
            SDL_LogInfo(SDL_LOG_CATEGORY_ERROR,"Shader already created");
    }

    void Driver::draw(Device & device)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        device.getScene()->drawAll();
        SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION,"drawAll done");
        SDL_GL_SwapWindow(device.getWindow()->getWindow());
        SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION,"window swaped");
    }

    void Driver::setWorld(maths::Matrix4 const& world)
    {
        GLuint world_loc = getShader("simple")->locate("world");
        glUniformMatrix4fv(world_loc,1,GL_TRUE, world.val);
    }
    void Driver::drawMesh(Mesh & mesh)
    {
        glDrawArrays(GL_TRIANGLES,0,mesh.getNbVertex());
    }
}
