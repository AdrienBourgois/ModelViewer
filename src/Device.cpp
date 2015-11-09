#include <new>
#include <GL/glew.h>
#include <iostream>
#include <fstream>
#include <string>

#include "Device.h"
#include "shader.h"
#include "SceneNode.h"
#include "Scene.h"

namespace id {

    void Device::create()
    {
        //this->initSubSystem(SubSystems::Timer);

        //this->createWindow();
        //this->createVideoDriver();

        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
        SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
        SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
        SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
        SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
        glEnable(GL_DEPTH_TEST);

        driver.create();

        this->prg_id = shader::makeAndUseProgram("simple");

        glClearColor(0.f, 0.f, 0.f, 1.f);

        this->setInitUniform(this->prg_id);

        while(this->shouldRun())
        {
            this->run();
        }

        glDisableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glUseProgram(0);
        glDeleteProgram(this->prg_id);
    }

    void Device::setInitUniform(auto prg_id)
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

    Device::~Device()
    {
        SDL_Quit();
    }

    Device::Device()
    {
        SDL_Init(SDL_INIT_EVERYTHING);
    }

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
        glClear(GL_COLOR_BUFFER_BIT);

        driver.draw();

        SDL_GL_SwapWindow(driver.getWindow());
    }

}
