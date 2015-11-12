#include "MeshSceneNode.h"

#include <GL/glew.h>
#include <SDL.h>
#include <vector>
#include "Driver.h"
#include "Shader.h"

namespace id{
    MeshSceneNode::MeshSceneNode(SceneNode * parent)
    :SceneNode(*parent->getScene(), parent)
    {
        this->mesh = new Mesh();
    }

    void MeshSceneNode::drawNode(Driver & driver)
    {
        if(getVisibility())
        {
            driver.setWorld(this->getGlobalTransform());
            driver.drawMesh(*this->mesh);
            for (auto child : getChildren())
                child->drawNode(driver);
        }
    }
}//id
