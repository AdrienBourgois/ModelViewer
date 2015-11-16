#ifndef __MESHOBJ_H_INCLUDED__
#define __MESHOBJ_H_INCLUDED__

#include <iostream>
#include <vector>
#include <string>
#include <SDL.h>
#include <GL/glew.h>
#include "Vector.h"
#include "Material.h"
#include <fstream>

namespace id
{
	class MeshObj
	{
	  public:
		MeshObj(std::string, MeshObj* first = nullptr);
		MeshObj(std::string);
		~MeshObj();

		void charger_obj(std::string, MeshObj*);
		void charger_mtl(std::string);
		void draw_model();
		void create();
		void initTexture();
		std::string doubleSlash(std::string);
		std::string remplacerSlash(std::string);
		std::string get_directory(std::string);
		std::vector<std::string> splitSpace(std::string);
		float* vector2float(std::vector<float>& tableau);
		

	  private:
		GLuint vbo;
                GLuint vao;

		GLuint texture = 0;
		int n_data;
		float *vertice, *normals, *textures, *colours;
		std::vector<Vector> ver,nor,tex;
		std::vector<Vector*> col;
		std::vector<unsigned int> iv,it,in;
		std::vector<Material*> materiaux;
		std::vector<float> tv,tc,tn,tt;
	};
}

#endif
