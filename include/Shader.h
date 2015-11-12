#ifndef __SHADER_INCLUDE__
#define __SHADER_INCLUDE__

#include <fstream>
#include <iostream>
#include <string>
#include <GL/glew.h>
#include <new>
#include <SDL.h>
#include <vector>

namespace id 
{
    class Shader
    {
        public:
            Shader(std::string const& name);
            ~Shader();
            void         initVertex(std::vector<GLfloat> shape);
            GLuint       getPrgId() {return prg_id;}
            GLint locate(const std::string& name);
        private:
            GLint vs_id;
            GLint fs_id;
            GLint prg_id;


            GLint loadShader(std::string const& name, GLint shader_type);
            GLint loadProgram();
            GLint makeAndUseProgram(std::string const& name);
    };
}//id


#endif
