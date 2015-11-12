#ifndef __SCENE_INCLUDE__
#define __SCENE_INCLUDE__

#include <SDL.h>
#include <GL/glew.h>
#include <vector>
#include <memory>
#include <new>
#include "SceneNode.h"
#include "maths/Matrix.h"
#include "CameraSceneNode.h"
namespace id
{
    class Driver;
    class Scene
    {
    public:
        Scene(Scene const&)=delete;
        Scene(Scene &&)=delete;
        ~Scene() = default;

        Scene& operator=(Scene const&)=delete;
        Scene& operator=(Scene &&)=delete;
    
        static std::unique_ptr<Scene> create (Driver & driver);
               void                   setRoot(SceneNode & root);
               SceneNode*             getRoot() {return root;}
               void                   locCamera();
               void                   drawAll();

    private:
        Scene (Driver & driver);
        SceneNode * root;
        Driver * driver;
        std::vector<CameraSceneNode*> camera;

/*




    void newSceneNode(std::vector<GLfloat>);
    void draw();

    void setMatrix(maths::Matrix4 matrix) {this->matrix = matrix;}

    maths::Matrix4 getMatrix() {return this->matrix;}

    void create();

    void setSceneUniform();
private:
    std::vector<SceneNode*> nodes;
    maths::Matrix4 matrix = maths::Matrix4::identity;
*/
    };

}//id

#endif
