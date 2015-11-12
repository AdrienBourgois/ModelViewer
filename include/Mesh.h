#ifndef _MESH_H
#define _MESH_H


#include <GL/glew.h>
#include <SDL.h>
#include <string>

namespace id{
    class Mesh
    {
        public:
            Mesh();
            ~Mesh();
            GLuint getVbo()      {return vbo;}
            GLuint getVao()      {return vao;}
            int    getNbVertex() {return nb_vertex;}
            GLuint locate(GLuint const& prg_id, std::string const& name);

        private:
            GLuint vbo;
            GLuint vao;
            int    nb_vertex;
    };
}//id


#endif
