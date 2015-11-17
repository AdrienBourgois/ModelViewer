#ifndef __GUIENVIRONMENT_H_INCLUDED__
#define __GUIENVIRONMENT_H_INCLUDED__

#include "imgui.h"
#include "GUIEnvironnement.h"

#include <SDL.h>
#include <SDL_syswm.h>
#include <GL/gl3w.h>

namespace id
{
	class GUIEnvironment
	{
	  public:
		GUIEnvironment();
		~GUIEnvironment();

        IMGUI_API bool ImGui_ImplSdlGL3_Init(SDL_Window *window);
        IMGUI_API void ImGui_ImplSdlGL3_Shutdown();
        IMGUI_API void ImGui_ImplSdlGL3_NewFrame();
        IMGUI_API bool ImGui_ImplSdlGL3_ProcessEvent(SDL_Event* event);
	  private:

        static SDL_Window*  g_Window = NULL;
        static bool         g_MousePressed[3] = { false, false, false };
        static float        g_MouseWheel = 0.0f;
        static int          g_ShaderHandle = 0, g_VertHandle = 0, g_FragHandle = 0;
        static int          g_AttribLocationTex = 0, g_AttribLocationProjMtx = 0;
        static int          g_AttribLocationPosition = 0, g_AttribLocationUV = 0, g_AttribLocationColor = 0;
        static unsigned int g_VboHandle = 0, g_VaoHandle = 0, g_ElementsHandle = 0;
        
	};
}

#endif
	
