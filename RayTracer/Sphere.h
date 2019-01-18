#pragma once
#include "Hitable.h"
class Sphere :public Hitable
{
public:

	Sphere();

	Sphere(glm::vec3 Origin,float Radius);

	~Sphere();

	void Set_Origin(glm::vec3 Origin);

	void Set_Radius(float Radius);

	glm::vec3 Get_Oringin();

	float Get_Radius();

	virtual bool Hit_Test(Ray & ray, Hit_Data & hit_data)override;


private:

	glm::vec3 Origin;

	float Radius;
};

