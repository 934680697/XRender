#include "Material_Metal.h"
#include "Light.h"
#include "Ray.h"
#include "Vector3.h"
#include "Hitable.h"
#include <math.h>


Material_Metal::Material_Metal():specular(Vector3(0,0,0)), roughness(0)
{

}


Material_Metal::Material_Metal(Vector3 diffuse_Color, Vector3 specular,float roughness):specular(specular), roughness(roughness)
{
	Material::Material(diffuse_Color);
}

Material_Metal::~Material_Metal()
{
}
Vector3 Material_Metal::Shading(Ray & ray, Light & light, Hit_Data & hit_data)
{
	Vector3 H = (ray.Get_Direction().Normalize() + light.Get_Rotation().Normalize()) / (ray.Get_Direction().Normalize() + light.Get_Rotation().Normalize()).Lengh();
	float R = (roughness + 2) / 8 * pow((hit_data.Hit_Normal.Dot(H.Normalize())), roughness);
	Vector3 F = specular + (1 - specular) * pow(1 - H.Normalize().Dot(ray.Get_Direction().Normalize()), 5);
	//Vector3 L = light.Get_Color() * hit_data.Hit_Normal.Dot(ray.GetDirection().Normalize());
	Vector3 L = light.Get_Color() * hit_data.Hit_Normal.Dot(light.Get_Rotation().Normalize());

	float Final_R = (F * R).R() * L.R();
	float Final_G = (F * R).G() * L.G();
	float Final_B = (F * R).B() * L.B();
	hit_data.Color = Vector3(Final_R, Final_G, Final_B);
	return Vector3(Final_R, Final_G, Final_B);

}

