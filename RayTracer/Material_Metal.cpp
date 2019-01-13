#include "Material_Metal.h"
#include "Light.h"
#include "Ray.h"
#include "Vector3.h"
#include "Hitable.h"
#include <math.h>


Material_Metal::Material_Metal():Specular(Vector3(0,0,0)), Roughness(0)
{

}


Material_Metal::Material_Metal(Vector3 Diffuse_Color, Vector3 Specular,float Roughness):Specular(Specular), Roughness(Roughness)
{
	Material::Material(Diffuse_Color);
}

Material_Metal::~Material_Metal()
{
}
Vector3 Material_Metal::Shading(Ray & ray, Light & light, Hit_Data & hit_data)
{
	Vector3 H = (ray.GetDirection().Normalize() + light.Get_Rotation().Normalize()) / (ray.GetDirection().Normalize() + light.Get_Rotation().Normalize()).Lengh();
	float R = (Roughness + 2) / 8 * pow((hit_data.Hit_Normal.Dot(H.Normalize())), Roughness);
	Vector3 F = Specular + (1 - Specular) * pow(1 - H.Normalize().Dot(ray.GetDirection().Normalize()), 5);
	//Vector3 L = light.Get_Color() * hit_data.Hit_Normal.Dot(ray.GetDirection().Normalize());
	Vector3 L = light.Get_Color() * hit_data.Hit_Normal.Dot(light.Get_Rotation().Normalize());

	float Final_R = (F * R).R() * L.R();
	float Final_G = (F * R).G() * L.G();
	float Final_B = (F * R).B() * L.B();
	hit_data.Color = Vector3(Final_R, Final_G, Final_B);
	return Vector3(Final_R, Final_G, Final_B);

}

