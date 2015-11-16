#ifndef __MATERIAL_H_INCLUDED__
#define __MATERIAL_H_INCLUDED__

#include <iostream>
#include <string>
#include "Vector.h"

namespace id
{
	class Material
	{
	  public:
        Material();
		Material(float,float,float,std::string);
		Material(Material*);
		~Material();

        std::string getName()const {return this->name;}
        Vector* getColor()const {return this->color;}
        float   getRed()const {return this->color->x;}
        float   getGreen()const {return this->color->y;}
        float   getBlue()const  {return this->color->z;}
    private:
        Vector* color;	
		std::string name;
	};	
}

#endif
