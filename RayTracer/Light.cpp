#include "Light.h"



Light::Light()
{
}


Light::~Light()
{
}

void Light::Set_Color(glm::vec3 color)
{
	this->color = color;
}

glm::vec3 Light::Get_Color()
{
	return this->color;
}
