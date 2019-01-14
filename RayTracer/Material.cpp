#include "Material.h"
#include "Light.h"



Material::Material()
{

}

Material::Material(Vector3 Diffuse_Color):diffuse_Color(diffuse_Color)
{

}

Material::~Material()
{

}
Vector3 Material::Shading(Ray & ray, Light & light,Hit_Data & hit_data)
{
	return Vector3();
}
