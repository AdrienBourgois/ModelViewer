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
#include "GUIEnvironment.h"

namespace id
{
	class System
	{
	  public:
		System(std::string const& path);
		~System();

        Window* getWindow() {return this->win;}
        MeshObj* getMesh() {return this->mesh;}
        Driver* getDriver() {return this->drv;}

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
        GUIEnvironment* gui;
		bool running = true;
	};
}

#endif
