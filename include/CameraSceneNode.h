#ifndef _CAMERA_SCENE_NODE_H
#define _CAMERA_SCENE_NODE_H

#include "maths/Matrix.h"
#include "SceneNode.h"



namespace id
{
    class CameraSceneNode : public SceneNode
    {
        public:
            CameraSceneNode(Scene & scene);
            ~CameraSceneNode();

            maths::Matrix4 calcView(float const translateX, float const traslateY, float const translateZ, float const rotateX, float const rotateY, float const rotateZi);
            void drawNode()=delete;

            maths::Matrix4 & getProj()                              {return proj;}
            void                  setProj(maths::Matrix4 const& proj);

        private:
            maths::Matrix4 proj;

    };
}
#endif
