#include "SceneNode.h"

namespace id
{
    SceneNode::SceneNode(Scene & scene, SceneNode* parent)
    {
        SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION,"creating scene node...");
        this->transform = maths::Matrix4::identity;
        this->scene = &scene;
        this->is_visible = true;
        this->parent = parent;
        SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION,"scene node created");
    }

    SceneNode::~SceneNode()
    {
    }

    void SceneNode::drawNode(Driver & driver)
    {
        for (unsigned int i = 0; i < getChildren().size(); ++i)
        {
            getChildren()[i]->drawNode(driver);
        }
    }

    void SceneNode::setTransform(maths::Matrix4 const& transform)
    {
        this->transform = transform;
    }

    void SceneNode::addChild(SceneNode & child)
    {
        if (&child != nullptr)
            this->children.push_back(&child);
        else
            SDL_LogInfo(SDL_LOG_CATEGORY_ERROR,"add empty child");
    }

    maths::Matrix4 SceneNode::getGlobalTransform()
    {
        if (parent)
            return parent->getGlobalTransform() * this->transform;
        return transform;
    }




 /*   void SceneNode::setNodeUniform(maths::Matrix4 sceneMatrix)
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
*/
}
