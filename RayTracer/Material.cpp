#include "Material.h"
#include "Light.h"
#include "Vector3.h"
#include "Hitable.h"



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
	hit_data.Color = diffuse_Color;
}

Vector3 Material::Cal_Reflect_Vector(Vector3 incident_light, Vector3 normal)
{
	return incident_light - normal * 2 * Vector3::DotProduct(incident_light, normal);
}
