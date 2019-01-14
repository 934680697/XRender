#pragma once
#include "Vector3.h"
struct  Hit_Data;
class Ray;
class Light;

class Material
{
public:

	Material();

	Material(Vector3 diffuse_Color);

	~Material();

	virtual void Shading(Ray & ray, Light & light, Hit_Data & hit_data);

protected:

	Vector3 Cal_Reflect_Vector(Vector3 incident_light, Vector3 normal);

	Vector3 diffuse_Color;

	


};

