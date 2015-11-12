#ifndef _MESH_SCENE_NODE_H
#define _MESH_SCENE_NODE_H



#include <GL/glew.h>
#include <SDL.h>


#include "SceneNode.h"
#include "Mesh.h"


namespace id{
    
    class MeshSceneNode : public SceneNode
    {
        public:
            MeshSceneNode(SceneNode * parent);
            ~MeshSceneNode()=default;
            
            void drawNode(Driver & driver) override;

        private:
            Mesh* mesh;
            
    };
}//id

#endif
