#include "Light.h"



Light::Light()
{
}


Light::~Light()
{
}

void Light::Set_Color(Vector3 color)
{
	this->color = color;
}

Vector3 Light::Get_Color()
{
	return this->color;
}
