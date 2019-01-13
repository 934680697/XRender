#pragma once
#include "Material.h"
class Light;
class Material_Metal : public Material
{
public:
	Material_Metal();

	Material_Metal(Vector3 Diffuse_Color,Vector3 Specular,float Roughness);

	~Material_Metal();

	virtual Vector3 Shading(Ray & ray, Light & light, Hit_Data & hit_data)override;


private:

	Vector3 Specular;

	float	     Roughness;
};

