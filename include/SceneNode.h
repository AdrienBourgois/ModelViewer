#ifndef __SCENE_NODE_INCLUDE__
#define __SCENE_NODE_INCLUDE__

#include <SDL.h>
#include <GL/glew.h>
#include <vector>
#include "maths/Matrix.h"

namespace id
{
    class Scene;
    class Driver;
    class SceneNode
    {
    public:

        SceneNode(Scene &, SceneNode *);
        virtual ~SceneNode();


        virtual                                Scene* getScene()            {return scene;}
        virtual maths::Matrix4 const&          getLocalTranforme()          {return transform;}
        virtual maths::Matrix4                 getGlobalTransform();
        virtual bool                           getVisibility()                {return is_visible;}
        virtual SceneNode*                     getParent()                  {return parent;}
        virtual void                           addChild(SceneNode & child);
        virtual std::vector<SceneNode*> const& getChildren()                {return children;}
        virtual void                           setTransform(maths::Matrix4 const& transform);
        virtual void                           drawNode(Driver & driver);

    private:
        maths::Matrix4 transform;
        Scene* scene;
        bool is_visible;
        std::vector<SceneNode*> children;
        SceneNode* parent;

    /*
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
    int size = 0;*/
    };
}//id

#endif
