#pragma once
#include "Material.h"
class Light;
class Material_Metal : public Material
{
public:
	Material_Metal();

	Material_Metal(Vector3 diffuse_Color,Vector3 specular,float roughness);

	~Material_Metal();

	virtual Vector3 Shading(Ray & ray, Light & light, Hit_Data & hit_data)override;


private:

	Vector3 specular;

	float	     roughness;
};

