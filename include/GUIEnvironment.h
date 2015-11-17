#ifndef __GUIENVIRONMENT_H_INCLUDED__
#define __GUIENVIRONMENT_H_INCLUDED__

#include "imgui.h"

#include <SDL.h>
#include <SDL_syswm.h>
#include <GL/glew.h>

namespace id
{
	class GUIEnvironment
	{
	  public:
		GUIEnvironment();
		~GUIEnvironment();

        IMGUI_API bool ImGui_Init(SDL_Window *window);
        IMGUI_API void ImGui_Shutdown();
        IMGUI_API void ImGui_NewFrame();
        IMGUI_API bool ImGui_ProcessEvent(SDL_Event* event);

	  private:

        SDL_Window*  g_Window = NULL;
        bool         g_MousePressed[3] = { false, false, false };
        float        g_MouseWheel = 0.0f;
	};
}

#endif
	
