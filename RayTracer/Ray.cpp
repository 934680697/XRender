#include "Ray.h"
Ray::Ray()
{

}
Ray::Ray(Vector3 Origin, Vector3 Direction)
{
	this->Origin		 = Origin;
	this->Direction = Direction;
}
Vector3 Ray::GetOrigin()
{
	return this->Origin;
}
Vector3 Ray::GetDirection()
{
	return this->Direction;
}

Vector3 Ray::Point_At_Parameter(float t)
{
	return Origin + (Direction * t);
}
