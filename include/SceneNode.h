#ifndef __SCENENODE_H_INCLUDED__
#define __SCENENODE_H_INCLUDED__

namespace id
{
	class SceneNode
	{
	  public:	
		SceneNode(SceneNode const&) = delete;
		SceneNode(SceneNode&&) = delete;
		~SceneNode();
	
		auto operator=(SceneNode const&) -> SceneNode& = delete;
	        auto operator=(SceneNode&&) -> SceneNode& = delete;
	
		void init();
	  private:
		SceneNode();
		
		std::unique_ptr<SceneNode> parent;

	};
}	

#endif
