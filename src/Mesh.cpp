#include "Mesh.h"

namespace id{


    Mesh::Mesh()
    {
        glGenVertexArrays(1,&this->vao);
        glGenBuffers(1,&this->vbo);
        this->nb_vertex = 0;
    }

    Mesh::~Mesh()
    {
    }

    GLuint Mesh::locate(GLuint const& prg_id, std::string const& name)
    {
        auto loc = glGetUniformLocation(prg_id, name.c_str());
        SDL_assert(loc >= 0);
        return loc;
    }
}//id
