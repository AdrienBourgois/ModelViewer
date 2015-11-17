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
		if ( x == false && y == false)
			this->world = maths::Matrix4x4::identity;

		if ( y == true && x == false)
			this->world = maths::Matrix4x4::rotateY(this->angle)*maths::Matrix4x4::rotateX(this->angle2);

		if ( x == true && y == false)
			this->world = maths::Matrix4x4::rotateX(this->angle2)*maths::Matrix4x4::rotateY(this->angle);
	
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
				case SDL_KEYDOWN:
					switch (event.key.keysym.sym)
					{
						case SDLK_LEFT:
							this->angle -= 2.f;
							y = true;
							x = false;
							return run;
							break;
						case SDLK_RIGHT:
							this->angle += 2.f;
							y = true;
							x = false;
							return run;
							break;
						case SDLK_UP:
							this->angle2 += 2.f;
							y = false;
							x = true;
							return run;
							break;
						case SDLK_DOWN:
							this->angle2 -= 2.f;
							y = false;
							x = true;
							return run;
							break;
					}
				break;
				case SDL_QUIT:
					run =  false;
					break;	
			}
		}
		return run;
	}	
}
