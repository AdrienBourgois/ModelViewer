#ifndef __DRIVER_INCLUDE__
#define __DRIVER_INCLUDE__


#include <new>
#include <memory>
#include <SDL.h>
#include <GL/glew.h>
#include <SDL.h>
#include <map>
#include <string>
#include <maths/Matrix.h>

#include "Shader.h"
#include "Scene.h"
#include "Mesh.h"
namespace id
{
    class Device;

    class Driver
    {
        public:
            Driver(Driver const&)=delete;
            Driver(Driver &&)=delete;
            ~Driver();

            static std::unique_ptr<Driver>       create(Device & device);
                   SDL_GLContext                 createContext(SDL_Window* window);
                   void                          addShader(std::string const& name);
                   std::map<std::string,Shader*> getShaders() {return shaders;}
                   Shader*                       getShader(std::string name) {return shaders[name];}
                   SDL_GLContext                 getContext() {return this->context;}
                   void                          setWorld(maths::Matrix4 const& world);

                   void                          draw(Device & device);
                   void                          drawMesh(Mesh & mesh);

        private:
            Driver(SDL_Window* window);
            SDL_GLContext context;
            std::map<std::string, Shader*> shaders;
    };
}

#endif
