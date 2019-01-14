#pragma once
#include "Material.h"
class Light;
class Material_Metal : public Material
{
public:
	Material_Metal();

	Material_Metal(Vector3 diffuse_Color,Vector3 specular,float roughness);

	~Material_Metal();

	virtual void Shading(Ray & ray, Light & light, Hit_Data & hit_data)override;
protected:

private:

	Vector3 specular;

	float	     roughness;
};

