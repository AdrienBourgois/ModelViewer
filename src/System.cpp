#include <iostream>
#include "System.h"
#include <GL/glew.h>
#include <string>
#include <SDL.h>
#include "maths/Matrix.h"

namespace id 
{
	System::System()
	{
		this->dev = new Device(this->win);
		this->win = new Window();
		this->drv = new Driver(*this->win);
		this->shader = new Shader();
		this->drv->setShader(*this->shader);
//		this->triforce = new Triforce(this->win);
//		this->scenemgr = new SceneManager(this->dev, this->triforce);
		this->mesh = new MeshObj("./assets/chara.obj", nullptr );
	}
	System::~System()
	{
		delete this->mesh;
		delete this->dev;
		delete this->win;
		delete this->drv;
		delete this->shader;
//		delete this->scenemgr;
//		delete this->triforce;
		this->dev = nullptr;
		this->win = nullptr;
		this->drv = nullptr;
		this->shader = nullptr;
//		this->scenemgr = nullptr;
		this->mesh = nullptr;
//		this->triforce = nullptr;
	}
	void System::init()
	{
		this->dev->create();
//		this->win->init();
		this->drv->init_Glew();
		this->shader->load_model();
		this->mesh->initTexture();
//		this->scenemgr->init();
		this->mesh->create();
	}
	void System::drawAll()
	{
		while (running)
       		{
                	SDL_Event ev;
	                while (SDL_PollEvent(&ev))
        	        {
                	        if (ev.type == SDL_QUIT)
                        	        running = false;
	                }
			this->drv->update();
                        this->drv->draw();
                        this->mesh->draw_model();
			SDL_GL_SwapWindow(this->win->getWindow());
        	}
		glDisableVertexAttribArray(0);
        	glDisableVertexAttribArray(1);
        	glBindBuffer(GL_ARRAY_BUFFER, 0);
	        glUseProgram(0);
       		glDeleteProgram(this->shader->getPrg());
	}
}
