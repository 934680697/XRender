#include "Material.h"
#include "Light.h"
#include "Vector3.h"



Material::Material()
{

}

Material::Material(Vector3 diffuse_Color):diffuse_Color(diffuse_Color)
{

}

Material::~Material()
{

}
void Material::Shading(Ray & ray, Light & light,Hit_Data & hit_data)
{
}

Vector3 Material::Cal_Reflect_Vector(Vector3 incident_light, Vector3 normal)
{
	return incident_light - normal * 2 * Vector3::DotProduct(incident_light, normal);
}
