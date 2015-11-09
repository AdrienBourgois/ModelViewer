#include "SceneNode.h"

namespace id
{
    void SceneNode::setNodeUniform(maths::Matrix4 sceneMatrix)
    {
        GLint prg_id;
        glGetIntegerv(GL_CURRENT_PROGRAM, &prg_id);

        auto world_loc = glGetUniformLocation(prg_id, "world");
        matrix *= maths::Matrix4::rotateY(1.f);
        maths::Matrix4 res = sceneMatrix * matrix;

        //std::cout << std::endl << "           -->- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -<--" << std::endl << std::endl;
        //matrix.showMatrix();
        //std::cout << std::endl << "           --<- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ->--" << std::endl << std::endl;

        glUniformMatrix4fv(world_loc, 1, GL_TRUE, res.val);
    }

}
