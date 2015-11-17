#include <new>
#include <GL/glew.h>
#include <SDL.h>
#include <iostream>
#include <fstream>
#include <string>
#include "maths/Matrix.h"
#include "maths/tools.h"

#include "Device.h"
#include "System.h"

namespace id
{
	void Device::create() 
	{
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
		SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
		SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
		SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
		SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	}
	Device::~Device()
	{
		SDL_Quit();
	}

	Device::Device(Window* win)
	{
		this->log->write_log("Creating device", "LOG.txt");
		this->win = win;
		SDL_Init(SDL_INIT_EVERYTHING);
		this->log->write_log("Device created", "LOG.txt");
	}

    void Device::setWindow(Window& window)
    {
        this->win = &window;
    }
}
