#include <GL/glew.h>
#include <SDL.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <iostream>
#include "Driver.h"

namespace id
{
	Driver::Driver(Window& window)
	{
		this->log->write_log("Creating driver", "LOG.txt");
		this->window = &window;
		this->log->write_log("Driver created", "LOG.txt");
	}

	Driver::~Driver()
	{
		SDL_GL_DeleteContext(this->glcontext);
	}

	void Driver::setShader(Shader & shader)
	{
		this->shader = &shader;
	}
	void Driver::init_Glew()
	{
		this->glcontext = SDL_GL_CreateContext(this->window->getWindow());
		glewExperimental = GL_TRUE;
        	auto status = glewInit();
	        SDL_assert(status == GLEW_OK);
	}
	void Driver::update()
	{
        this->world = maths::Matrix4x4::identity;

        this->world = maths::Matrix4x4::rotateY(this->angleY)*maths::Matrix4x4::rotateX(this->angleX)*maths::Matrix4x4::rotateZ(this->angleZ);

        this->view = maths::Matrix4::translate(0.f, 0.f, 100.f).inverse();
        this->proj = maths::Matrix4::perspective(rad(90.f), 1.f, 0.1f, 1000.f);
	}

	void Driver::draw()
	{
		this->world_loc = glGetUniformLocation(this->shader->getPrg(), "world");
	        this->view_loc = glGetUniformLocation(this->shader->getPrg(), "view");
        	this->proj_loc = glGetUniformLocation(this->shader->getPrg(), "proj");
	        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
        	glMatrixMode(GL_MODELVIEW);

	        glUniformMatrix4fv(this->world_loc, 1, GL_TRUE, this->world.val);
        	glUniformMatrix4fv(this->view_loc, 1, GL_TRUE, this->view.val);
	        glUniformMatrix4fv(this->proj_loc, 1, GL_TRUE, this->proj.val);

        	glUseProgram(this->shader->getPrg());
	}
	bool Driver::keyEvent(bool run)
	{
		SDL_Event event;
		while ( SDL_PollEvent(&event))
		{
			switch (event.type)
			{
				case SDL_QUIT:
					run =  false;
					break;	
			}
		}
		return run;
	}	
}
