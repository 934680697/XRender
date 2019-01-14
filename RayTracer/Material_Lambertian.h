#pragma once
#include "Material.h"

class Material_Lambertian : public Material
{
public:

	Material_Lambertian();

	Material_Lambertian(Vector3 diffuse_Color);

	~Material_Lambertian();

	virtual void Shading(Ray & ray, Light & light, Hit_Data & hit_data)override;

protected:

	Vector3 Random_in_Unit_Sphere();
};

