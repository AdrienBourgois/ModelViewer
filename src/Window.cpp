#include <GL/glew.h>
#include <SDL.h>
#include <iostream>

#include "Window.h"

namespace id 
{
	Window::Window()
	{
		this->log->write_log("Creating window", "LOG.txt");
		this->init();
		this->log->write_log("Window created", "LOG.txt");
	}
	Window::~Window()
	{
		SDL_DestroyWindow(this->window);
	}
	void Window::init()
	{
		this->window = SDL_CreateWindow("OpenGL 4.2", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 700, 700, SDL_WINDOW_OPENGL);
	}
}
