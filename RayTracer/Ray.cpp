#include "Ray.h"
Ray::Ray()
{

}
Ray::Ray(glm::vec3 origin, glm::vec3 direction)
	:origin(origin), 
	direction(direction)
{
}
glm::vec3 Ray::Get_Origin()
{
	return this->origin;
}
glm::vec3 Ray::Get_Direction()
{
	return this->direction;
}

glm::vec3 Ray::Point_At_Parameter(float t)
{
	return origin + (direction * t);
}
