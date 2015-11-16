#include <GL/glew.h>
#include <SDL.h>
#include <iostream>
#include "Driver.h"

namespace id
{
	Driver::Driver(Window& window)
	{
		this->window = &window;
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
		this->world = maths::Matrix4x4::rotateY(this->angle);
        	this->view = maths::Matrix4::translate(0.f, 0.f, 100.f).inverse();
	        this->proj = maths::Matrix4::perspective(rad(90.f), 1.f, 0.1f, 1000.f);
        	this->angle += 1.f;
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

}
