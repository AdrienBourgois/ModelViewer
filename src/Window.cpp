#include <GL/glew.h>
#include <SDL.h>
#include <iostream>

#include "Window.h"

namespace id 
{
	Window::Window()
	{
		this->init();
	}
	Window::~Window()
	{
		SDL_DestroyWindow(this->window);
	}
	void Window::init()
	{
		this->window = SDL_CreateWindow("OpenGL 4.2", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1000, 1000, SDL_WINDOW_OPENGL);
	}
}
