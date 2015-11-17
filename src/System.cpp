#include <iostream>
#include "System.h"
#include <GL/glew.h>
#include <string>
#include <SDL.h>
#include "maths/Matrix.h"
#include "GUIEnvironment.h"
#include "imgui.h"

namespace id 
{
	System::System(std::string const& path)
	{
        	this->dev = new Device();
	        this->win = new Window();
        	this->dev->setWindow(*this->win);
	        this->gui = new GUIEnvironment();
		this->drv = new Driver(*this->win);
		this->shader = new Shader();
		this->drv->setShader(*this->shader);
		this->mesh = new MeshObj(path, nullptr);
	}
	System::~System()
	{
	        this->gui->ImGui_Shutdown();

		delete this->mesh;
		delete this->dev;
		delete this->win;
		delete this->drv;
		delete this->shader;
        	delete this->gui;

		this->dev = nullptr;
		this->win = nullptr;
		this->drv = nullptr;
		this->shader = nullptr;
		this->mesh = nullptr;
        	this->gui = nullptr;
	}
	void System::init()
	{
		this->dev->create();
		this->drv->init_Glew();
        this->gui->ImGui_Init(*this);
		this->shader->load_model();
		this->mesh->initTexture();
		this->mesh->create();
	}
	void System::drawAll()
	{
		while (running)
        {
            SDL_Event ev;

            while (SDL_PollEvent(&ev))
            {
                this->gui->ImGui_ProcessEvent(&ev);
                if (ev.type == SDL_QUIT)
                    running = false;
            }
            this->gui->ImGui_NewFrame();

            this->drv->update();
            this->drv->draw();
            this->mesh->draw_model();

            this->gui->showGUI();
            ImGui::Render();

            SDL_GL_SwapWindow(this->win->getWindow());
        }

		glDisableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glUseProgram(0);
        glDeleteProgram(this->shader->getPrg());
	}
}
