#ifndef __SHADER_INCLUDE__
#define __SHADER_INCLUDE__

#include <fstream>
#include <iostream>
#include <string>
#include <GL/glew.h>
#include <new>
#include <SDL.h>

namespace shader {

    GLuint loadShader(std::string const& name, GLint shader_type);
    GLuint loadProgram(GLuint vs_id, GLuint fs_id);

    GLuint makeAndUseProgram(std::string const& name);
}


#endif
