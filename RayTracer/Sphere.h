#pragma once
#include "Hitable.h"
class Sphere :public Hitable
{
public:

	Sphere();

	Sphere(Vector3 Origin,float Radius);

	~Sphere();

	void Set_Origin(Vector3 Origin);

	void Set_Radius(float Radius);

	Vector3 Get_Oringin();

	float Get_Radius();

	virtual bool Hit_Test(Ray & ray, Hit_Data & hit_data)override;


private:

	Vector3 Origin;

	float Radius;
};

