#include "Sphere.h"
#include "glm/glm.hpp"


Sphere::Sphere()
	:Origin(0,0,0),
	Radius(0.3)
{
	
}


Sphere::Sphere(glm::vec3 Origin, float Radius):Origin(Origin),Radius(Radius)
{

}

Sphere::~Sphere()
{
}
void Sphere::Set_Origin(glm::vec3 Origin)
{
	this->Origin = Origin;
}

void Sphere::Set_Radius(float Radius)
{
	this->Radius = Radius;
}

glm::vec3 Sphere::Get_Oringin()
{
	return this->Origin;
}
float Sphere::Get_Radius()
{
	return this->Radius;
}
bool Sphere::Hit_Test(Ray & ray, Hit_Data & hit_data)
{
	bool bIs_Hit = false;
	glm::vec3 OC = ray.Get_Origin() - this->Origin;
	float a = glm::dot(ray.Get_Direction(), ray.Get_Direction());
	float b = 2 * glm::dot(ray.Get_Direction(), OC);
	float c = glm::dot(OC, OC) - this->Radius * this->Radius;
	float discriminant = b * b - 4 * a *c;
	if (discriminant >= 0)
	{
		float Hit_t = (-1 * b - sqrt(discriminant)) / (2.0 * a);
		if (Hit_t > 0)
		{
			bIs_Hit = true;
			hit_data.Hit_Position = ray.Point_At_Parameter(Hit_t);
			hit_data.Hit_Normal = glm::normalize(hit_data.Hit_Position - Origin);
		}
	}
	return bIs_Hit;

}
