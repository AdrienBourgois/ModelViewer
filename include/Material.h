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
		Material(float,float,float,std::string);
		Material(Material*);
		~Material();

		Vector* color;
		
		std::string name;
	};	
}

#endif
