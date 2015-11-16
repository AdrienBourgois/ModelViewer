#ifndef __SCENEMANAGER_H_INCLUDED__
#define __SCENEMANAGER_H_INCLUDED__

#include "Device.h"
#include "Triforce.h"
#include <memory>
#include <GL/glew.h>

namespace id
{
	class SceneManager
	{
	  public:
		SceneManager(Device*, Triforce*);
		~SceneManager();
		void init();

	  private:
		Triforce* triforce;
		Device* dev;
		GLuint vbo;
		GLuint vao;	
	};
}
	
#endif
