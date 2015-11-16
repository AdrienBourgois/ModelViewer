#include "Material.h"

namespace id
{
    Material::Material()
    {
        this->name = "default";
        this->color->x = 255;
        this->color->y = 255;
        this->color->z = 255;
    }
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
