#pragma once
#include "Vector3.h"
class Ray
{
public:

	Ray();

	Ray(Vector3 Origin, Vector3 Direction);

	Vector3 GetOrigin();

	Vector3 GetDirection();

	Vector3 Point_At_Parameter(float t);

private:

	Vector3 Origin;

	Vector3 Direction;
};
