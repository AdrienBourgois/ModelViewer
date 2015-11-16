#include "MeshObj.h"
#include <SDL_image.h>
#include <cstdio>

namespace id
{
	MeshObj::MeshObj(std::string s, MeshObj *first)
	{
		charger_obj(s,first);
	}
	MeshObj::~MeshObj()
	{
		free(vertice);
		free(textures);
		glDeleteBuffers(1, &(this->vbo));
		glDeleteVertexArrays(1, &(this->vao));

		ver.clear();
                tex.clear();

                iv.clear();
                it.clear();

		for(unsigned int i = 0 ; i < materiaux.size() ; i++)
			delete materiaux[i];

		materiaux.clear();
	}
	void MeshObj::charger_obj(std::string name, MeshObj* first)
	{
		std::ifstream file;
		std::string ligne = "";
		std::string curname = "";
		file.open(name, std::ios::in);
		SDL_assert(file.is_open());
		file.seekg(0, std::ios::end);
		auto file_len = file.tellg();
		file.seekg(0, std::ios::beg);
		int cur_pos = 0;
	    while (cur_pos < file_len)
	    {
		std::getline(file, ligne);	

		if(ligne[0]=='v')
		{
			if(ligne[1]==' ')
			{
				char x[255],y[255],z[255];
        			sscanf(ligne.c_str(),"v %s %s %s",x,y,z);
        			ver.push_back(Vector(strtod(x,NULL),strtod(y,NULL),strtod(z,NULL)));
			}
			else if(ligne[1]=='t')
			{
				char x[255],y[255];
        			sscanf(ligne.c_str(),"vt %s %s",x,y);
			        tex.push_back(Vector(strtod(x,NULL),strtod(y,NULL)));
    			}
			else if(ligne[1]=='n')
			{
				char x[255],y[255],z[255];
	        		sscanf(ligne.c_str(),"vn %s %s %s",x,y,z);
			        nor.push_back(Vector(strtod(x,NULL),strtod(y,NULL),strtod(z,NULL)));
			}
		}
		else if(ligne[0]=='f')
		{
    			ligne=doubleSlash(ligne);
			ligne=remplacerSlash(ligne);

    			std::vector<std::string> termes=splitSpace(ligne.substr(2));

    			int ndonnees=(int)termes.size()/3;
    			for(int i = 0 ; i < (ndonnees == 3?3:4 ); i++)
    			{
        			iv.push_back(strtol(termes[i*3].c_str(),NULL,10)-1);
        			it.push_back(strtol(termes[i*3+1].c_str(),NULL,10)-1);
        			in.push_back(strtol(termes[i*3+2].c_str(),NULL,10)-1);
    			}

    			for(unsigned int i = 0; i < materiaux.size(); i++)
        			if(materiaux[i]->getName() == curname)
        			{
            				for(int j = 0 ; j < 4; j++)
                			col.push_back(materiaux[i]->getColor());
					break;
				}
        	}

		else if(ligne[0]=='m'&&first==NULL)
		    charger_mtl(get_directory(name) + ligne.substr(7));

		else if(ligne[0] == 'u')
		    curname=ligne.substr(7);

		cur_pos = file.tellg();
	   }
			
		file.close();

		this->n_data = 0;
		for(unsigned int i = 0; i < iv.size(); i++)
    			if(iv[i]<ver.size())
    			{

			        tv.push_back(ver[iv[i]].x);
			        tv.push_back(ver[iv[i]].y);
			        tv.push_back(ver[iv[i]].z);

				tv.push_back(tex[it[i]].x);
                                tv.push_back(-tex[it[i]].y);

				++(this->n_data);
			}
			
		vertice=vector2float(tv);
		textures=vector2float(tt);
	}
	std::string MeshObj::doubleSlash(std::string s)
	{
		std::string s1 = "";	
		for(unsigned int i = 0 ; i < s.size(); i++)
    		{
        		if(i < s.size()-1 && s[i] == '/' && s[i+1] == '/')
        		{
            			s1 += "/1/";
            			i++;
        		}
        		else
            		s1 += s[i];
    		}
    		return s1;
	}

	std::string MeshObj::remplacerSlash(std::string s)
	{
		std::string ret = "";
    		for(unsigned int i = 0 ; i < s.size();i++)
    		{	
        		if(s[i] == '/')
            			ret += ' ';
        		else
            			ret += s[i];
    		}
    		return ret;
	}

	std::string MeshObj::get_directory(std::string s)
	{
		std::string s1 = "", s2 = "";
		for ( unsigned int i = 0; i < s.size() ; ++i)
		{
			if (s[i] == '/' || s[i] == '\\')
			{
				s1 += s2 + "/";
				s2 = "";
			}
			else 
				s2 += s[i];
		}

		return s1;
	}

	std::vector<std::string> MeshObj::splitSpace(std::string s)
	{
    		std::vector<std::string> ret;
		std::string s1 = "";
    		for(unsigned int i = 0; i < s.size(); i++)
    		{	
        		if(s[i] == ' ' || i == s.size()-1)
        		{
            			if(i == s.size()-1)
                			s1 += s[i];

            			ret.push_back(s1);
            			s1 = "";
		        }
        		else
           			s1 += s[i];
     		}
    		return ret;
	}
	float* MeshObj::vector2float(std::vector<float>& tableau)
	{
		float* t = NULL;
		t = (float*)malloc(tableau.size()* sizeof(float));
		if (t == NULL || tableau.empty())
		{
			float *t1 = (float*)malloc(sizeof(float)*3);
			for(int i=0;i<3;i++)
            			t1[i]=0.;
        		return t1;
    		}

    		for(unsigned int i=0;i<tableau.size();i++)
        		t[i]=tableau[i];

    		return t;
	}
	
	void MeshObj::charger_mtl(std::string name)
	{
		std::ifstream file(name.c_str(), std::ios::in);
		std::string ligne,curname = "";

		if (ligne[0] == 'n')
			curname = ligne.substr(7);

		else if (ligne[0] == 'K' && ligne[1] == 'd')
		{
			std::vector<std::string> termes=splitSpace(ligne.substr(3));
			materiaux.push_back(new Material((float)strtod(termes[0].c_str(),NULL),(float)strtod(termes[1].c_str(),NULL),(float)strtod(termes[2].c_str(),NULL),curname));
		}
		else if(ligne[0] == 'm' && ligne[5] == 'd')
		{
			std::string f = get_directory(name)+ligne.substr(7);
		}
		else if(ligne[0] == 'd')
		{	
			std::string n=ligne.substr(2);
    			materiaux[materiaux.size()-1]->getColor()->a=strtod(n.c_str(),NULL);
		}		

	}
	void MeshObj::draw_model()
	{	
		glBindTexture(GL_TEXTURE_2D,this->texture);
 		glDrawArrays(GL_TRIANGLES, 0,this->n_data);	
	}
	void MeshObj::create()
	{
		glGenVertexArrays(1, &(this->vao));
	        glGenBuffers(1,&(this->vbo));
                glBindVertexArray(this->vao);
                glBindBuffer(GL_ARRAY_BUFFER, this->vbo);
		glBufferData(GL_ARRAY_BUFFER, this->tv.size() * sizeof(tv[0]), this->tv.data() , GL_STATIC_READ);
                glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5*sizeof(GLfloat), nullptr);
                glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5*sizeof(GLfloat),(void*)(3*sizeof(GLfloat)));
		
		glEnableVertexAttribArray(0);
                glEnableVertexAttribArray(1);
		glClearColor(0.f,0.f,0.f,1.f);
	}
	void MeshObj::initTexture()
	{
		SDL_Surface* surf = IMG_Load("./media/texture_chara_UV2.png");

		glClearColor(.5,.5,.5,0);
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_TEXTURE_2D);
		glGenTextures(1, &this->texture);
		glBindTexture(GL_TEXTURE_2D,this->texture);
		glTexImage2D(GL_TEXTURE_2D, 0,GL_RGB, surf->w , surf->h, 0, GL_RGB, GL_UNSIGNED_BYTE, surf->pixels);

		SDL_FreeSurface(surf);
		
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glBindTexture(GL_TEXTURE_2D, 0);
	}
}		

