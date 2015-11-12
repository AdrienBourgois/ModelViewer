#include "CameraSceneNode.h"



namespace id{

    CameraSceneNode::CameraSceneNode(Scene & scene)
    :SceneNode(scene, nullptr)
    {
        this->proj = maths::Matrix4::identity;
    }

    CameraSceneNode::~CameraSceneNode()
    {
    }

    maths::Matrix4 CameraSceneNode::calcView(float const translateX, float const translateY, float const translateZ, float const rotateX, float const rotateY, float const rotateZ)
    {
        return maths::Matrix4::translate(translateX, translateY, translateZ).rotateX(rotateX).rotateY(rotateY).rotateZ(rotateZ).inverse();
    }

    void CameraSceneNode::setProj(maths::Matrix4 const& proj)
    {
        this->proj = proj;
    }

}//id
