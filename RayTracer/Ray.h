#pragma once
#include "glm/vec3.hpp"
class Ray
{
public:

	Ray();

	Ray(glm::vec3 origin, glm::vec3 direction);

	glm::vec3 Get_Origin();

	glm::vec3 Get_Direction();

	glm::vec3 Point_At_Parameter(float t);

private:

	glm::vec3 origin;

	glm::vec3 direction;
};
