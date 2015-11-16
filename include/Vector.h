#ifndef __VECTOR_H_INCLUDED__
#define __VECTOR_H_INCLUDED__

namespace id
{
	class Vector
	{
          public:
		Vector(float,float,float);
		Vector(float,float);
		Vector(float);
		~Vector();
	
	 	Vector operator=(const Vector &v);

		float x,y,z,a;
	};
}

#endif
