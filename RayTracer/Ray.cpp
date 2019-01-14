#include "Ray.h"
Ray::Ray()
{

}
Ray::Ray(Vector3 origin, Vector3 direction)
	:origin(origin), 
	direction(direction)
{
}
Vector3 Ray::Get_Origin()
{
	return this->origin;
}
Vector3 Ray::Get_Direction()
{
	return this->direction;
}

Vector3 Ray::Point_At_Parameter(float t)
{
	return origin + (direction * t);
}
