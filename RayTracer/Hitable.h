#pragma once
#include "Vector3.h"
#include "Ray.h"

struct Hit_Data
{
	Vector3 Color;
	Vector3 Hit_Position;
	Vector3 Hit_Normal;
	Vector3 reflectance;
	Vector3 reflect_vector;
};

class Hitable
{
public:

	Hitable();

	~Hitable();

	virtual bool Hit_Test(Ray & ray, Hit_Data & hit_data) { return false; }

};

