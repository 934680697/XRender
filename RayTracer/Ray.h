#pragma once
#include "Vector3.h"
class Ray
{
public:

	Ray();

	Ray(Vector3 origin, Vector3 direction);

	Vector3 Get_Origin();

	Vector3 Get_Direction();

	Vector3 Point_At_Parameter(float t);

private:

	Vector3 origin;

	Vector3 direction;
};
