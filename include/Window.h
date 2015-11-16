#ifndef __WINDOW_H_INCLUDED__
#define __WINDOW_H_INCLUDED__

#include <memory>
#include <GL/glew.h>
#include <SDL.h>

namespace id
{
	class Window 
	{
	  public:
		Window();
		~Window();
		SDL_Window* getWindow() {return this->window;}
		void init(); 
	  private:
		SDL_Window* window;
	};
}

#endif
