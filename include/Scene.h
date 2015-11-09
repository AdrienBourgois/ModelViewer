#ifndef __SCENE_INCLUDE__
#define __SCENE_INCLUDE__

#include <SDL.h>
#include <GL/glew.h>
#include <vector>
#include "SceneNode.h"
#include "maths/Matrix.h"

namespace id
{
struct Scene
{
public:
    Scene() = default;
    ~Scene() = default;

    void newSceneNode(std::vector<GLfloat>);
    void draw();

    void setMatrix(maths::Matrix4 matrix) {this->matrix = matrix;}

    maths::Matrix4 getMatrix() {return this->matrix;}

    void create();

    void setSceneUniform();
private:
    std::vector<SceneNode*> nodes;
    maths::Matrix4 matrix = maths::Matrix4::identity;
};

}

#endif
