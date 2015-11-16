#ifndef __SYSTEM_H_INCLUDED__
#define __SYSTEM_H_INCLUDED__

#include "Device.h"
#include "Driver.h"
#include "Window.h"
#include "SceneManager.h"
#include "MeshObj.h"
#include "Triforce.h"
#include "Shader.h"
#include "Driver.h"

namespace id
{
	class System
	{
	  public:
		System();
		~System();

		void init();
		void drawAll();
	  private:
		Driver* drv;
		Device* dev;
		SceneManager* scenemgr;
		Window* win;
		MeshObj* mesh;
		Triforce* triforce;
		Shader* shader;
		bool running = true;
	};
}

#endif
