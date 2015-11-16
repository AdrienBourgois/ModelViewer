#include <GL/glew.h>
#include <SDL.h>
#include <iostream>

#include "SceneManager.h"

namespace id 
{
	SceneManager::SceneManager(Device* dev, Triforce* triforce)
	{
		this->dev = dev;
		this->triforce = triforce;
	}
	SceneManager::~SceneManager()
	{
		glDeleteBuffers(1, &(this->vbo));
		glDeleteVertexArrays(1, &(this->vao));
	}
	void SceneManager::init()
	{
		this->triforce->load();
		GLfloat triangle[] =
        	{
               		0.5f,0.0f, 0.1f,        0.75f, 0.6f, 0.0f, 1.0f,
               		0.0f, 1.0f, 0.1f,       0.5f, 0.3f, 0.0f, 1.0f,
               		-0.5f,0.0f, 0.1f,       0.75f, 0.6f, 0.0f, 1.0f,

               		1.0f, -1.0f, 0.1f,      1.0f, 1.0f, 0.0f, 1.0f,
               		0.5f, 0.0f, 0.1f,       0.75f, 0.6f, 0.0f, 1.0f,
               		0.0f, -1.0f, 0.1f,      1.0f, 1.0f, 0.0f, 1.0f,

               		-0.5f, 0.0f, 0.1f,      0.75f, 0.6f, 0.0f, 1.0f,
               		-1.0f, -1.0f, 0.1f,     1.0f, 1.0f, 0.0f, 1.0f,
               		0.0f, -1.0f, 0.1f,      1.0f, 1.0f, 0.0f, 1.0f,

               		-0.5f,0.0f, -0.1f,       0.75f, 0.6f, 0.0f, 1.0f,
               		0.0f, 1.0f, -0.1f,       0.5f, 0.3f, 0.0f, 1.0f,
               		0.5f,0.0f, -0.1f,        0.75f, 0.6f, 0.0f, 1.0f,

               		0.0f, -1.0f, -0.1f,      1.0f, 1.0f, 0.0f, 1.0f,
               		0.5f, 0.0f, -0.1f,        0.75f, 0.6f, 0.0f, 1.0f,
               		1.0f, -1.0f, -0.1f,      1.0f, 1.0f, 0.0f, 1.0f,

               		-1.0f, -1.0f, -0.1f,     1.0f, 1.0f, 0.0f, 1.0f,
               		-0.5f, 0.0f, -0.1f,      0.75f, 0.6f, 0.0f, 1.0f,
               		0.0f, -1.0f, -0.1f,     1.0f, 1.0f, 0.0f, 1.0f,

         	        0.0f, 1.0f, 0.1f,      0.5f, 0.3f, 0.0f, 1.0f,
	                0.0f, 1.0f, -0.1f,      0.5f, 0.3f, 0.0f, 1.0f,
               		-1.0f, -1.0f, -0.1f,     1.0f, 1.0f, 0.0f, 1.0f,

               		-1.0f, -1.0f, -0.1f,     1.0f, 1.0f, 0.0f, 1.0f,
         	        -1.0f, -1.0f, 0.1f,     1.0f, 1.0f, 0.0f, 1.0f,
	                0.0f, 1.0f, 0.1f,      0.5f, 0.3f, 0.0f, 1.0f,

        	        0.0f, 1.0f, -0.1f,      0.5f, 0.3f, 0.0f, 1.0f,
	                0.0f, 1.0f, 0.1f,      0.5f, 0.3f, 0.0f, 1.0f,
               		1.0f, -1.0f, 0.1f,     1.0f, 1.0f, 0.0f, 1.0f,

               		1.0f, -1.0f, 0.1f,     1.0f, 1.0f, 0.0f, 1.0f,
	                1.0f, -1.0f, -0.1f,     1.0f, 1.0f, 0.0f, 1.0f,
           	        0.0f, 1.0f, -0.1f,      0.5f, 0.3f, 0.0f, 1.0f,

          	        0.5f,0.0f, 0.1f,        0.7f, 0.5f, 0.0f, 1.0f,
	                -0.5f,0.0f, 0.1f,       0.7f, 0.5f, 0.0f, 1.0f,
               		-0.5f,0.0f, -0.1f,       0.7f, 0.5f, 0.0f, 1.0f,

         	        -0.5f,0.0f, -0.1f,       0.7f, 0.5f, 0.0f, 1.0f,
	                0.5f,0.0f, -0.1f,        0.7f, 0.5f, 0.0f, 1.0f,
               		0.5f,0.0f, 0.1f,        0.7f, 0.5f, 0.0f, 1.0f,

                	0.5f, 0.0f, 0.1f,       0.7f, 0.5f, 0.0f, 1.0f,
         	        0.5f, 0.0f, -0.1f,       0.7f, 0.5f, 0.0f, 1.0f,
	                0.0f, -1.0f, -0.1f,      0.75f, 0.6f, 0.0f, 1.0f,

          	        0.0f, -1.0f, -0.1f,      0.75f, 0.6f, 0.0f, 1.0f,
	                0.0f, -1.0f, 0.1f,      0.75f, 0.6f, 0.0f, 1.0f,
               		0.5f, 0.0f, 0.1f,       0.7f, 0.5f, 0.0f, 1.0f,

	                -0.5f, 0.0f, -0.1f,       0.7f, 0.5f, 0.0f, 1.0f,
         	        -0.5f, 0.0f, 0.1f,       0.7f, 0.5f, 0.0f, 1.0f,
	                0.0f, -1.0f, 0.1f,      0.75f, 0.6f, 0.0f, 1.0f,

         	        0.0f, -1.0f, 0.1f,      0.75f, 0.6f, 0.0f, 1.0f,
	                0.0f, -1.0f, -0.1f,      0.75f, 0.6f, 0.0f, 1.0f,
               		-0.5f, 0.0f, -0.1f,       0.7f, 0.5f, 0.0f, 1.0f,

               		1.0f, -1.0f, 0.1f,     1.0f, 1.0f, 0.0f, 1.0f,
	                -1.0f, -1.0f, 0.1f,     1.0f, 1.0f, 0.0f, 1.0f,
         	        -1.0f, -1.0f, -0.1f,     1.0f, 1.0f, 0.0f, 1.0f,

          	        -1.0f, -1.0f, -0.1f,     1.0f, 1.0f, 0.0f, 1.0f,
	                1.0f, -1.0f, -0.1f,     1.0f, 1.0f, 0.0f, 1.0f,
               		1.0f, -1.0f, 0.1f,     1.0f, 1.0f, 0.0f, 1.0f,

        	};
	        glGenVertexArrays(1, &(this->vao));
	        glGenBuffers(1,&(this->vbo));
        	glBindVertexArray(this->vao);
	        glBindBuffer(GL_ARRAY_BUFFER, this->vbo);
	        glBufferData(GL_ARRAY_BUFFER, sizeof(triangle), triangle, GL_STATIC_READ);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 7*sizeof(GLfloat), nullptr);
	        glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 7*sizeof(GLfloat),(void*)(3*sizeof(GLfloat)));

	       	glEnableVertexAttribArray(0);
		glEnableVertexAttribArray(1);
	       	glClearColor(0.f, 0.f, 0.f ,1.f);
	}
}
