#include "Material.h"

namespace id
{
	Material::Material(float r, float g, float b, std::string n)
	:name(n)
	{
		color->x = r;
		color->y = g;
		color->z = b;
	}
	
	Material::Material(Material *material)
	{
		color = material->color;
		name = material->name;
	}
	
	Material::~Material()
	{
	}
}
