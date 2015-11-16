#ifndef __SHADER_H_INCLUDED__
#define __SHADER_H_INCLUDED__

#include <memory>
#include <GL/glew.h>
#include <iostream>
#include <string>
#include <SDL.h>

namespace id
{	
	class Shader
	{
	  public: 
		Shader();
		~Shader();

		GLint getPrg()const {return this->prg_id;}

		GLint loadShader(std::string const& name, GLint shader_type);
		void loadProgram();
		void load_model();

	  private:
		GLuint prg_id;
        	GLint vs_id;
	        GLint fs_id;
	};
}

#endif
