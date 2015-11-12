#include <new>
#include <GL/glew.h>
#include <iostream>
#include <fstream>
#include <string>

#include "Device.h"
#include "Shader.h"
#include "SceneNode.h"
#include "Scene.h"

namespace id {

    std::unique_ptr<Device> Device::create()
    {
        Device * dev = new (std::nothrow) Device;
        SDL_assert(dev);
        SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION,"device created");
        dev->window = Window::create();
        SDL_assert(dev->getWindow());
        SDL_assert(dev->getWindow()->getWindow());
        SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION,"window created");
        dev->driver = Driver::create(*dev);
        SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION,"driver created");
        dev->scene = Scene::create(*dev->getDriver());
        SDL_assert(dev->getScene());
        SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION,"Scene created");
        dev->initGlew();
        SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION,"Glew created");
        dev->getDriver()->addShader("simple");

        //this->prg_id = shader::makeAndUseProgram("simple");

        glClearColor(0.f, 0.f, 0.f, 1.f);
        
        //this->setInitUniform(this->prg_id);

        while(dev->shouldRun())
        {
            dev->run();
        }

       /* glDisableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glUseProgram(0);
        glDeleteProgram(this->prg_id);
*/
        return std::unique_ptr<Device>(dev);
    }

    Device::Device()
    {
        SDL_Init(SDL_INIT_EVERYTHING);
        SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION,"SDL initialised");
        setAttribute();
        SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION,"Attribut set");
        this->driver = nullptr;
        this->window = nullptr;
        this->scene = nullptr;
    }

    Device::~Device()
    {
        SDL_Quit();
    }

    void Device::setAttribute()
    {
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
        SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
        SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
        SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
        SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
        glEnable(GL_DEPTH_TEST);
    }

    void Device::initGlew()
    {
        glewExperimental = GL_TRUE;
        auto status = glewInit();
        SDL_assert(status == GLEW_OK);
    }

  /*  void Device::setInitUniform(auto prg_id)
    {
        auto world_loc = glGetUniformLocation(prg_id, "world");
        auto view_loc = glGetUniformLocation(prg_id, "view");
        auto proj_loc = glGetUniformLocation(prg_id, "proj");

        maths::Matrix4 world = maths::Matrix4::identity;
        maths::Matrix4 view = maths::Matrix4::translate(0.f, 0.f, 5.f);
        view.inverse();
        maths::Matrix4 proj = maths::Matrix4::perspective(maths::Matrix4x4::degreesToRadian(90.f), 1.f, 0.1f, 100.f);

        glUniformMatrix4fv(world_loc, 1, GL_TRUE, world.val);
        glUniformMatrix4fv(view_loc, 1, GL_TRUE, view.val);
        glUniformMatrix4fv(proj_loc, 1, GL_TRUE, proj.val);
    }
 */  


    bool Device::shouldRun()
    {
        SDL_Event ev;
        while(SDL_PollEvent(&ev))
        {
            if (ev.type == SDL_QUIT)
                return false;
        }

        const Uint8 *keyState = SDL_GetKeyboardState(NULL);

        if(keyState[SDL_SCANCODE_ESCAPE])
            return false;

        return true;
    }

    void Device::run()
    {
        this->driver->draw(*this);
    }

}
