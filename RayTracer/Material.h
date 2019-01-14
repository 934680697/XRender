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

	virtual Vector3 Shading(Ray & ray, Light & light, Hit_Data & hit_data);

private:

	Vector3 diffuse_Color;


};

