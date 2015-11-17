#ifndef __DRIVER_H_INCLUDED__
#define __DRIVER_H_INCLUDED__

#include <memory>
#include <GL/glew.h>
#include "Device.h"
#include "Window.h"
#include "Shader.h"
#include "Log.h"
#include "maths/tools.h"
#include "maths/Matrix.h"

namespace id
{
	class Driver
	{
	  public:
		Driver(Window&);
		~Driver();

		void setShader(Shader & shader);
		void init_Glew();
		void update();
		void draw();
		bool keyEvent(bool);

	  private:
		Shader* shader;
		Window* window;
		Log* log;
		SDL_GLContext glcontext;

		GLint world_loc;
        	GLint view_loc;
	        GLint proj_loc;

		maths::Matrix4 view;
        	maths::Matrix4 world;
	        maths::Matrix4 proj;

		float angle = 0.f;
		float angle2 = 0.f;
	};
}

#endif
