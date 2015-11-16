#ifndef __TRIFORCE_H_INCLUDED__
#define __TRIFORCE_H_INCLUDED__

#include <memory>
#include "maths/Matrix.h"
#include "maths/tools.h"
#include "Device.h"

namespace id
{
	class Triforce
	{
	  public:
		Triforce(Window*);
		~Triforce();

		GLint getPrg() {return this->prg_id;}

		GLuint loadShader(std::string const& name, GLint shader_type);
        	GLuint loadProgram();	
		void load();
		void update();
		void draw();
	  private:
		Shader* shader;
		Window* win;
		Device *dev;
	
		GLint prg_id;
        	GLint vs_id;
	        GLint fs_id;

		maths::Matrix4 view;
	        maths::Matrix4 world;
        	maths::Matrix4 proj;

		GLint world_loc;
        	GLint view_loc;
	        GLint proj_loc;
		
		float angle = 0.f;
	};
}

#endif
