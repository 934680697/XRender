#include "Material_Lambertian.h"
#include "Hitable.h"
#include <random>
#define RAMDOM_ZERO_TO_ONE static_cast <float> (rand()) / static_cast <float> (RAND_MAX)



Material_Lambertian::Material_Lambertian()
{
}


Material_Lambertian::Material_Lambertian(Vector3 diffuse_Color)
{
	this->diffuse_Color = diffuse_Color;
}

Material_Lambertian::~Material_Lambertian()
{
}

void Material_Lambertian::Shading(Ray & ray, Light & light, Hit_Data & hit_data)
{
	Vector3 target = hit_data.Hit_Position + hit_data.Hit_Normal + Random_in_Unit_Sphere();
	hit_data.reflect_vector = target - hit_data.Hit_Position;
	hit_data.reflectance	    = diffuse_Color;
}

Vector3 Material_Lambertian::Random_in_Unit_Sphere()
{
	Vector3 Point;
	do
	{
		float x = RAMDOM_ZERO_TO_ONE;
		float y = RAMDOM_ZERO_TO_ONE;
		float z = RAMDOM_ZERO_TO_ONE;
		Point = Vector3(RAMDOM_ZERO_TO_ONE, RAMDOM_ZERO_TO_ONE, RAMDOM_ZERO_TO_ONE) * 2 - Vector3(1, 1, 1);
	} while (Vector3::DotProduct(Point, Point) >= 1.0f);
	return Point;
}

#undef  RAMDOM_ZERO_TO_ONE