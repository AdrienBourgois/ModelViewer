#include "Scene.h"
#include <iostream>
#include "SceneNode.h"

namespace id
{
    void Scene::create()
    {
        std::vector<GLfloat> cube =
        {
            0.5f, -0.5f,  0.5f,    1.000f, 0.000f, 0.000f, 1.0f,
           -0.5f, -0.5f,  0.5f,    1.000f, 0.000f, 0.000f, 1.0f,
            0.5f,  0.5f,  0.5f,    1.000f, 0.000f, 0.000f, 1.0f,

           -0.5f,  0.5f,  0.5f,    1.000f, 0.000f, 0.000f, 1.0f,
            0.5f,  0.5f, -0.5f,    1.000f, 0.000f, 0.000f, 1.0f,
           -0.5f,  0.5f, -0.5f,    1.000f, 0.000f, 0.000f, 1.0f,

            0.5f, -0.5f, -0.5f,    1.000f, 0.000f, 0.000f, 1.0f,
           -0.5f, -0.5f, -0.5f,    1.000f, 0.000f, 0.000f, 1.0f,
            0.5f,  0.5f,  0.5f,    1.000f, 0.000f, 0.000f, 1.0f,

           -0.5f,  0.5f,  0.5f,    1.000f, 0.000f, 0.000f, 1.0f,
            0.5f,  0.5f, -0.5f,    1.000f, 0.000f, 0.000f, 1.0f,
           -0.5f,  0.5f, -0.5f,    1.000f, 0.000f, 0.000f, 1.0f,

            0.5f, -0.5f, -0.5f,    1.000f, 0.000f, 0.000f, 1.0f,
           -0.5f, -0.5f,  0.5f,    1.000f, 0.000f, 0.000f, 1.0f,
           -0.5f, -0.5f, -0.5f,    1.000f, 0.000f, 0.000f, 1.0f,

            0.5f, -0.5f,  0.5f,    1.000f, 0.000f, 0.000f, 1.0f,
           -0.5f, -0.5f,  0.5f,    1.000f, 0.000f, 0.000f, 1.0f,
           -0.5f,  0.5f, -0.5f,    1.000f, 0.000f, 0.000f, 1.0f,

           -0.5f, -0.5f, -0.5f,    1.000f, 0.000f, 0.000f, 1.0f,
           -0.5f,  0.5f,  0.5f,    1.000f, 0.000f, 0.000f, 1.0f,
            0.5f, -0.5f, -0.5f,    1.000f, 0.000f, 0.000f, 1.0f,

            0.5f,  0.5f,  0.5f,    1.000f, 0.000f, 0.000f, 1.0f,
            0.5f, -0.5f,  0.5f,    1.000f, 0.000f, 0.000f, 1.0f,
            0.5f,  0.5f, -0.5f,    1.000f, 0.000f, 0.000f, 1.0f,
        };

        this->newSceneNode(cube);

    }

    void Scene::newSceneNode(std::vector<GLfloat> data)
    {
        SceneNode* node = new SceneNode;

        node->setSize(data.size() / 7);

        glGenBuffers(1, &node->vbo);
        glGenVertexArrays(1, &node->vao);

        glBindVertexArray(node->vao);
        glBindBuffer(GL_ARRAY_BUFFER, node->vbo);
        glBufferData(GL_ARRAY_BUFFER, sizeof(data) * data.size(), data.data(), GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 7*sizeof(GLfloat), nullptr);
        glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 7*sizeof(GLfloat), (void*)(3*sizeof(GLfloat)));

        glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);

        //glDeleteBuffers(1, &node->vbo);
        nodes.push_back(node);
    }

    void Scene::draw()
    {
        for (uint i = 0; i < nodes.size(); ++i)
        {
            glBindVertexArray(nodes[i]->vao);
            glBindBuffer(GL_ARRAY_BUFFER, nodes[i]->vbo);

            nodes[i]->setNodeUniform(getMatrix());

            //nodes[1]->setMatrix(nodes[1]->getMatrix() *= maths::Matrix4::rotateX(0.1f));

            glDrawArrays(GL_TRIANGLES, 0, nodes[i]->getSize());
        }
    }

    void Scene::setSceneUniform()
    {
        GLint prg_id;
        glGetIntegerv(GL_CURRENT_PROGRAM, &prg_id);

        auto world_loc = glGetUniformLocation(prg_id, "world");
        matrix *= maths::Matrix4::rotateY(1.f);

        matrix.showMatrix();
        std::cout << "------------------------------------------------------------------------------------------" << std::endl << std::endl;

        glUniformMatrix4fv(world_loc, 1, GL_TRUE, matrix.val);
    }


}