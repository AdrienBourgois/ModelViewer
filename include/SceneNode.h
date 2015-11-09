#ifndef __SCENE_NODE_INCLUDE__
#define __SCENE_NODE_INCLUDE__

#include <SDL.h>
#include <GL/glew.h>
#include <vector>
#include "maths/Matrix.h"

namespace id
{
struct SceneNode
{
public:
    SceneNode() = default;
    ~SceneNode() = default;

    void setVertexArray(GLuint vao) {this->vao = vao;}
    void setBuffer(GLuint vbo) {this->vbo = vbo;}
    void setData(std::vector<GLfloat>) {this->data = data;}
    void setMatrix(maths::Matrix4 matrix) {this->matrix = matrix;}
    void setSize(int size) {this->size = size;}

    void setNodeUniform(maths::Matrix4);

    GLuint getVertexArray() {return this->vao;}
    GLuint getBuffer() {return this->vbo;}
    std::vector<GLfloat> getData() {return this->data;}
    maths::Matrix4 getMatrix() {return this->matrix;}
    int getSize() {return size;}

    GLuint vbo;
    GLuint vao;
private:
    std::vector<GLfloat> data;
    maths::Matrix4 matrix = maths::Matrix4::identity;
    int size = 0;
};

}

#endif
