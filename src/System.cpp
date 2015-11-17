#include <iostream>
#include "System.h"
#include <GL/glew.h>
#include <string>
#include <SDL.h>
#include "maths/Matrix.h"

namespace id 
{
	System::System(std::string const& path)
	{
		this->dev = new Device(this->win);
		this->win = new Window();
		this->drv = new Driver(*this->win);
		this->shader = new Shader();
		this->drv->setShader(*this->shader);
		this->mesh = new MeshObj(path, nullptr);
	}
	System::~System()
	{
		delete this->mesh;
		delete this->dev;
		delete this->win;
		delete this->drv;
		delete this->shader;
		this->dev = nullptr;
		this->win = nullptr;
		this->drv = nullptr;
		this->shader = nullptr;
		this->mesh = nullptr;
	}
	void System::init()
	{
		this->dev->create();
		this->drv->init_Glew();
		this->shader->load_model();
		this->mesh->initTexture();
		this->mesh->create();
	}
	void System::drawAll()
	{
		while (running)
       		{
			running = this->drv->keyEvent(running);
			this->drv->update();
                        this->drv->draw();
                        this->mesh->draw_model();
			SDL_GL_SwapWindow(this->win->getWindow());
        	}
		glDisableVertexAttribArray(0);
        	glBindBuffer(GL_ARRAY_BUFFER, 0);
	        glUseProgram(0);
       		glDeleteProgram(this->shader->getPrg());
	}
}
