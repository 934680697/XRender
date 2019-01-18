#include "Material_Metal.h"
#include "Light.h"
#include "Ray.h"
#include "Hitable.h"
#include "glm/glm.hpp"
#include <math.h>


Material_Metal::Material_Metal()
	:specular(glm::vec3(0,0,0)), 
	roughness(0)
{

}


Material_Metal::Material_Metal(glm::vec3 diffuse_Color, glm::vec3 specular,float roughness):specular(specular), roughness(roughness)
{
	this->diffuse_Color = diffuse_Color;
}

Material_Metal::~Material_Metal()
{
}
void  Material_Metal::Shading(Ray & ray, Light & light, Hit_Data & hit_data)
{
	/*glm::vec3 H = (ray.Get_Direction().Normalize() + light.Get_Rotation().Normalize()) / (ray.Get_Direction().Normalize() + light.Get_Rotation().Normalize()).Lengh();

	float R = (roughness + 2) / 8 * pow((hit_data.Hit_Normal.Dot(H.Normalize())), roughness);

	glm::vec3 F = specular + (1 - specular) * pow(1 - H.Normalize().Dot(ray.Get_Direction().Normalize()), 5);

	glm::vec3 L = light.Get_Color() * hit_data.Hit_Normal.Dot(light.Get_Rotation().Normalize());

	float Final_R = (F * R).R() * L.R();
	float Final_G = (F * R).G() * L.G();
	float Final_B = (F * R).B() * L.B();
	hit_data.Color = glm::vec3(Final_R, Final_G, Final_B);
	return glm::vec3(Final_R, Final_G, Final_B);*/
	hit_data.reflect_vector = Cal_Reflect_Vector(ray.Get_Direction(), glm::normalize(hit_data.Hit_Normal));
	hit_data.reflectance	    = diffuse_Color;
	
}

