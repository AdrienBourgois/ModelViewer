#ifndef __DEVICE_H_INCLUDED__
#define __DEVICE_H_INCLUDED__

#include <memory>
#include <GL/glew.h>
#include "maths/Matrix.h"
#include "Window.h"
#include "MeshObj.h"
#include "Shader.h"
#include "Log.h"

namespace id
{
    class Device
    {
    public:
	Device();
	Device(Window*);
        ~Device();

        void create();
	void load_model();
	void load();
	void update();
	void draw();
	void init_Glew();

	GLuint loadShader(std::string const& name, GLint shader_type);
	GLuint loadProgram();
    private:
	Window* win;
	MeshObj* mesh;
	Shader* shader;
	Log* log;

	maths::Matrix4 view;
	maths::Matrix4 world;
	maths::Matrix4 proj;

	GLint prg_id;
	GLint vs_id;
	GLint fs_id;

	GLint world_loc;
	GLint view_loc;
	GLint proj_loc;

	float angle = 0.f;
    };
}

#endif
