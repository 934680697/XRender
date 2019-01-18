#include "Material.h"
#include "Light.h"
#include "Hitable.h"
#include "glm/glm.hpp"



Material::Material()
{

}

Material::Material(glm::vec3 diffuse_Color):diffuse_Color(diffuse_Color)
{

}

Material::~Material()
{

}
void Material::Shading(Ray & ray, Light & light,Hit_Data & hit_data)
{
	hit_data.Color = diffuse_Color;
}

glm::vec3 Material::Cal_Reflect_Vector(glm::vec3 incident_light, glm::vec3 normal)
{
	return incident_light - normal * 2.0f * glm::dot(incident_light, normal);
}
