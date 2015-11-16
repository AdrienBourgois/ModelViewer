#include <iostream>
#include "Vector.h"

namespace id
{
	Vector::Vector(float px, float py, float pz)
	:x(px),y(py),z(pz)
	{
	}

	Vector::Vector(float px, float py)
	:x(px),y(py)
	{
	}

	Vector::Vector(float pa)
	:a(pa)
	{
	}
	
	Vector::~Vector()
	{
	}
	
	Vector Vector::operator=(const Vector &fv)
	{
		this->x = fv.x;
		this->y = fv.y;
		this->z = fv.z;
		this->a = fv.a;

		return *this;
	}
}
